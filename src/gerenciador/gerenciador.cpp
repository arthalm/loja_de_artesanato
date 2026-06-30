#include "gerenciador.h"
#include "../usuario/cliente/cliente.h"
#include "../usuario/artesao/artesao.h"
#include "../produto/pintura/pintura.h"
#include "../produto/escultura/escultura.h"
#include "../produto/artesanato/artesanato.h"

#include <fstream>
#include <sstream>
#include <iostream>

GerenciadorArquivos::GerenciadorArquivos(std::string arqUsr, std::string arqProd, std::string arqPed)
: arquivoUsuarios(arqUsr), arquivoProdutos(arqProd), arquivoPedidos(arqPed) {}

void GerenciadorArquivos::salvarDados(std::vector<Usuario *> u, std::vector<Produto *> p, std::vector<Pedido*> ped)
{
    // parte de Usuarios
    std::ofstream fusr(arquivoUsuarios);
    if (!fusr.is_open())
    {
        std::cerr << "Erro ao abrir " << arquivoUsuarios << " para escrita.\n";
        return;
    }

    for (Usuario *usr : u)
    {
        // se usuario eh um cliente
        if (Cliente *c = dynamic_cast<Cliente *>(usr))
        {
            const Endereco &e = c->getEndereco();
            fusr << "CLIENTE|"
                 << c->getNome() << "|"
                 << c->getLogin() << "|"
                 << c->getCpf() << "|"
                 << c->getSenha() << "|"
                 << e.getDestinatario() << "|"
                 << e.getLogradouro() << "|"
                 << e.getNumero() << "|"
                 << e.getComplemento() << "|"
                 << e.getBairro() << "|"
                 << e.getCidade() << "|"
                 << e.getEstado() << "|"
                 << e.getCEP() << "|"
                 << c->getSaldoAtual() << "\n";
        }
        // se usuario eh um artesao
        else if (Artesao *a = dynamic_cast<Artesao *>(usr))
        {
            fusr << "ARTESAO|"
                 << a->getNome() << "|"
                 << a->getLogin() << "|"
                 << a->getCpf() << "|"
                 << a->getSenha() << "|"
                 << a->getNomeAtelie() << "|"
                 << a->getBiografia() << "\n";
        }
    }
    fusr.close();

    // parte de Produtos
    std::ofstream fprod(arquivoProdutos);
    if (!fprod.is_open())
    {
        std::cerr << "Erro ao abrir " << arquivoProdutos << " para escrita.\n";
        return;
    }

    for (Produto *prod : p)
    {
        // se produto eh uma pintura
        if (Pintura *pin = dynamic_cast<Pintura *>(prod))
        {
            fprod << "PINTURA|"
                  << pin->getTitulo() << "|"
                  << pin->getPreco() << "|"
                  << pin->getQuantidadeEstoque() << "|"
                  << pin->getTipoTinta() << "|"
                  << pin->getPossuiMoldura() << "|"
                  << static_cast<int>(pin->getTamanho()) << "|"
                  << pin->getIDartesao() << "\n";
        }
        // se produto eh uma escultura
        else if (Escultura *esc = dynamic_cast<Escultura *>(prod))
        {
            fprod << "ESCULTURA|"
                  << esc->getTitulo() << "|"
                  << esc->getPreco() << "|"
                  << esc->getQuantidadeEstoque() << "|"
                  << esc->getMaterial() << "|"
                  << static_cast<int>(esc->getPeso()) << "|"
                  << esc->getIDartesao() << "\n";
        }
        // se produto eh um artesanato
        else if (Artesanato *art = dynamic_cast<Artesanato *>(prod))
        {
            fprod << "ARTESANATO|"
                  << art->getTitulo() << "|"
                  << art->getPreco() << "|"
                  << art->getQuantidadeEstoque() << "|"
                  << art->getTempo() << "|"
                  << art->getFeitoSobEncomenda() << "|"
                  << art->getIDartesao() << "\n";
        }
    }
    fprod.close();

    // parte de pedido
    std::ofstream fped(arquivoPedidos);
    if (!fped.is_open())
    {
        std::cerr << "Erro ao abrir " << arquivoPedidos << " para escrita.\n";
        return;
    }

    for (Pedido *ped : ped)
    {
        const Endereco &e = ped->getEnderecoEntrega();
        fped << "PEDIDO|"
             << ped->getClienteLogin() << "|"
             << static_cast<int>(ped->getStatus()) << "|"
             << e.getDestinatario() << "|"
             << e.getLogradouro() << "|"
             << e.getNumero() << "|"
             << e.getComplemento() << "|"
             << e.getBairro() << "|"
             << e.getCidade() << "|"
             << e.getEstado() << "|"
             << e.getCEP();
        for (Produto *p : ped->getProdutos())
        {
            fped << "|" << p->getID();
        }
        fped << "\n";
    }
    fped.close();
}

void GerenciadorArquivos::carregarDados(std::vector<Usuario *> &u, std::vector<Produto *> &p, std::vector<Pedido *> ped)
{
    // parte de usuarios
    std::ifstream fusr(arquivoUsuarios);
    if (fusr.is_open())
    {
        std::string linha;
        while (std::getline(fusr, linha))
        {
            std::stringstream ss(linha);
            std::string tipo;
            std::getline(ss, tipo, '|');

            if (tipo == "CLIENTE")
            {
                std::string nm, log, cpf, pwd;
                std::string dest, logr, comp, bair, cid, est, cep;
                int num;
                double saldo;
                std::getline(ss, nm, '|');
                std::getline(ss, log, '|');
                std::getline(ss, cpf, '|');
                std::getline(ss, pwd, '|');
                std::getline(ss, dest, '|');
                std::getline(ss, logr, '|');
                ss >> num;
                ss.ignore();
                std::getline(ss, comp, '|');
                std::getline(ss, bair, '|');
                std::getline(ss, cid, '|');
                std::getline(ss, est, '|');
                std::getline(ss, cep, '|');
                ss >> saldo;
                Endereco endereco(
                    dest,
                    logr,
                    num,
                    comp,
                    bair,
                    cid,
                    est,
                    cep);
                Cliente *c = new Cliente(nm, log, cpf, pwd, saldo);
                c->setEndereco(endereco);
                u.push_back(c);
            }
            else if (tipo == "ARTESAO")
            {
                std::string nm, log, cpf, pwd, atelie, bio;
                std::getline(ss, nm, '|');
                std::getline(ss, log, '|');
                std::getline(ss, cpf, '|');
                std::getline(ss, pwd, '|');
                std::getline(ss, atelie, '|');
                std::getline(ss, bio, '|');
                u.push_back(new Artesao(nm, log, cpf, pwd, atelie, bio));
            }
        }
        fusr.close();
    }

    // parte de produtos
    std::ifstream fprod(arquivoProdutos);
    if (fprod.is_open())
    {
        std::string linha;
        while (std::getline(fprod, linha))
        {
            std::stringstream ss(linha);
            std::string tipo;
            std::getline(ss, tipo, '|');

            if (tipo == "PINTURA")
            {
                std::string ttl, tinta;
                double preco;
                int quantidade, moldura, tamanho, idArt;
                std::getline(ss, ttl, '|');
                ss >> preco;
                ss.ignore();
                ss >> quantidade;
                ss.ignore();
                std::getline(ss, tinta, '|');
                ss >> moldura;
                ss.ignore();
                ss >> tamanho;
                ss.ignore();
                ss >> idArt;
                p.push_back(new Pintura(ttl, preco, tinta,
                                        static_cast<bool>(moldura),
                                        static_cast<Dimensao>(tamanho),
                                        quantidade));
            }
            else if (tipo == "ESCULTURA")
            {
                std::string ttl, mat;
                double preco;
                int quantidade, peso, idArt;
                std::getline(ss, ttl, '|');
                ss >> preco;
                ss.ignore();
                ss >> quantidade;
                ss.ignore();
                std::getline(ss, mat, '|');
                ss >> peso;
                ss.ignore();
                ss >> idArt;
                p.push_back(new Escultura(ttl, preco, mat,
                                          static_cast<Peso>(peso),
                                          quantidade));
            }
            else if (tipo == "ARTESANATO")
            {
                std::string ttl;
                double preco;
                int quantidade, tempo, sob, idArt;
                std::getline(ss, ttl, '|');
                ss >> preco;
                ss.ignore();
                ss >> quantidade;
                ss.ignore();
                ss >> tempo;
                ss.ignore();
                ss >> sob;
                ss.ignore();
                ss >> idArt;
                p.push_back(new Artesanato(ttl, preco, tempo, static_cast<bool>(sob), quantidade));
            }
        }
        fprod.close();
    }

    //parte de pedidos
    std::ifstream fped("pedidos.txt");
    if (fped.is_open())
    {
        std::string linha;
        while (std::getline(fped, linha))
        {
            std::stringstream ss(linha);
            std::string tipo, loginCliente, statusStr;
            std::getline(ss, tipo, '|');
            std::getline(ss, loginCliente, '|');
            std::getline(ss, statusStr, '|');

            Cliente *c = nullptr;
            for (Usuario *usr : u)
            {
                if (Cliente *cl = dynamic_cast<Cliente *>(usr))
                {
                    if (cl->getLogin() == loginCliente)
                    {
                        c = cl;
                        break;
                    }
                }
            }

            if (!c)
            {continue;}

            //ajusta o status dos pedidos
            //pq foram salvos como string de numero no arquivo
            Pedido *pedido = new Pedido(*c);
            int status = std::stoi(statusStr);
            for (int i = 0; i < status; i++)
            {pedido->avancarEstado();}

            // adiciona os produtos pelo ID
            std::string idStr;
            while (std::getline(ss, idStr, '|'))
            {
                int id = std::stoi(idStr);
                for (Produto *prod : p)
                {
                    if (prod->getID() == id)
                    {
                        pedido->adicionarProduto(prod);
                        break;
                    }
                }
            }
            ped.push_back(pedido);
        }
        fped.close();
    }
}