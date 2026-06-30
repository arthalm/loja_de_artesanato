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
    int quantidadeEstoque;

public:
    Produto(std::string ttl, double p, int qtd = 0);

    int getID();
    std::string getTitulo();
    double getPreco();
    int getIDartesao();
    int getQuantidadeEstoque();
    void setQuantidadeEstoque(int qtd);

    bool removerEstoque(int qtd = 1);

    static void setProximoID(int valor);

    virtual double calcularPreco() = 0;

    virtual void exibirDados();

    virtual ~Produto() {}
};

#endif