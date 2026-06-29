#include "gerenciador.h"
#include "../usuario/cliente/cliente.h"
#include "../usuario/artesao/artesao.h"
#include "../produto/pintura/pintura.h"
#include "../produto/escultura/escultura.h"
#include "../produto/artesanato/artesanato.h"

#include <fstream>
#include <sstream>
#include <iostream>

GerenciadorArquivos::GerenciadorArquivos(std::string arqUsr, std::string arqProd)
    : arquivoUsuarios(arqUsr), arquivoProdutos(arqProd) {}

void GerenciadorArquivos::salvarDados(std::vector<Usuario *> u, std::vector<Produto *> p)
{
    //parte de Usuarios
    std::ofstream fusr(arquivoUsuarios);
    if (!fusr.is_open())
    {
        std::cerr << "Erro ao abrir " << arquivoUsuarios << " para escrita.\n";
        return;
    }

    for (Usuario *usr : u)
    {
        //se usuario eh um cliente
        if (Cliente *c = dynamic_cast<Cliente *>(usr))
        {
            fusr << "CLIENTE|"
                 << c->getNome() << "|"
                 << c->getLogin() << "|"
                 << c->getCpf() << "|"
                 << c->getSenha() << "|"
                 << c->getEndereco() << "|"
                 << c->getSaldoAtual() << "\n";
        }
        //se usuario eh um artesao
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

    //parte de Produtos
    std::ofstream fprod(arquivoProdutos);
    if (!fprod.is_open())
    {
        std::cerr << "Erro ao abrir " << arquivoProdutos << " para escrita.\n";
        return;
    }

    for (Produto *prod : p)
    {
        //se produto eh uma pintura
        if (Pintura *pin = dynamic_cast<Pintura *>(prod))
        {
            fprod << "PINTURA|"
                  << pin->getTitulo() << "|"
                  << pin->getPreco() << "|"
                  << pin->getTipoTinta() << "|"
                  << pin->getPossuiMoldura() << "|"
                  << static_cast<int>(pin->getTamanho()) << "|"
                  << pin->getIDartesao() << "\n";
        }
        //se produto eh uma escultura
        else if (Escultura *esc = dynamic_cast<Escultura *>(prod))
        {
            fprod << "ESCULTURA|"
                  << esc->getTitulo() << "|"
                  << esc->getPreco() << "|"
                  << esc->getMaterial() << "|"
                  << static_cast<int>(esc->getPeso()) << "|"
                  << esc->getIDartesao() << "\n";
        }
        //se produto eh um artesanato
        else if (Artesanato *art = dynamic_cast<Artesanato *>(prod))
        {
            fprod << "ARTESANATO|"
                  << art->getTitulo() << "|"
                  << art->getPreco() << "|"
                  << art->getTempo() << "|"
                  << art->getFeitoSobEncomenda() << "|"
                  << art->getIDartesao() << "\n";
        }
    }
    fprod.close();
}