#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
    int id;
    std::string titulo;
    double precoBase;
    int idArtesao;
    

    static int proximoID;

public:
    Produto(std::string ttl, double p);

    int getID();
    std::string getTitulo();
    double getPreco();
    int getIDartesao();
};

#endif

int Produto::proximoID = 0;