#include "produto.h"
#include <string>
#include <iostream>

Produto::Produto(std::string ttl, double p): titulo(ttl), precoBase(p)
{}

int Produto::getID()
{return id;}

std::string Produto::getTitulo()
{return titulo;}

double Produto::getPreco()
{return precoBase;}

int Produto::getIDartesao()
{return idArtesao;}

void Produto::exibirDados()
{
    std::cout << titulo << " (#" << id << ") - R$ " << precoBase; 
}