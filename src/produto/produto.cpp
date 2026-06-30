#include "produto.h"
#include <string>
#include <iostream>

static int proximoID = 1;

Produto::Produto(std::string ttl, double p, int qtd) : id(proximoID++), titulo(ttl), precoBase(p), idArtesao(0), quantidadeEstoque(qtd)
{
}

int Produto::getID()
{
    return id;
}

std::string Produto::getTitulo()
{
    return titulo;
}

double Produto::getPreco()
{
    return precoBase;
}

int Produto::getIDartesao()
{
    return idArtesao;
}

int Produto::getQuantidadeEstoque()
{
    return quantidadeEstoque;
}

void Produto::setQuantidadeEstoque(int qtd)
{
    quantidadeEstoque = qtd;
}

bool Produto::removerEstoque(int qtd)
{
    if (qtd <= 0 || qtd > quantidadeEstoque)
    {
        return false;
    }
    quantidadeEstoque -= qtd;
    return true;
}

void Produto::setProximoID(int valor)
{}

void Produto::exibirDados()
{
    std::cout << titulo << " (#" << id << ") - R$ " << precoBase
              << " - Estoque: " << quantidadeEstoque;
}