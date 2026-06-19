#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto
{
protected:
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

    static void setProximoID (int valor);

    virtual double calcularFrete() = 0;

    virtual void exibirDados();
};

#endif