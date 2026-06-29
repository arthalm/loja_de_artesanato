#ifndef GERENCIADOR_ARQUIVOS_H
#define GERENCIADOR_ARQUIVOS_H

#include <vector>
#include <string>
#include "../usuario/usuario.h"
#include "../produto/produto.h"

class GerenciadorArquivos
{
private:
    std::string arquivoUsuarios;
    std::string arquivoProdutos;

public:
    GerenciadorArquivos(std::string arqUsr = "usuarios.txt", std::string arqProd = "produtos.txt");

    void salvarDados(std::vector<Usuario *> u, std::vector<Produto *> p);
    void carregarDados(std::vector<Usuario *> &u, std::vector<Produto *> &p);
};

#endif