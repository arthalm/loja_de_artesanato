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
}