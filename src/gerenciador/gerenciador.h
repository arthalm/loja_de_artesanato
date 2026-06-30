#ifndef GERENCIADOR_ARQUIVOS_H
#define GERENCIADOR_ARQUIVOS_H

#include <vector>
#include <string>
#include "../usuario/usuario.h"
#include "../produto/produto.h"
#include "../pedido/pedido.h"

class GerenciadorArquivos
{
private:
    std::string arquivoUsuarios;
    std::string arquivoProdutos;
    std::string arquivoPedidos;

public:
    GerenciadorArquivos(std::string arqUsr = "usuarios.txt", std::string arqProd = "produtos.txt", std::string arqPed = "pedidos.txt");

    void salvarDados(std::vector<Usuario *> u, std::vector<Produto *> p, std::vector<Pedido*> ped);
    void carregarDados(std::vector<Usuario *> &u, std::vector<Produto *> &p, std::vector<Pedido *> &ped);
};

#endif