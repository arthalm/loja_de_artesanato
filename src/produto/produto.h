#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    int id;
    std::string titulo;
    double preco;

    static int proximoID;

public:
    Produto(std::string ttl, double p);

    std::string getTitulo();
    double getPreco();
};

#endif

int Produto::proximoID = 0;