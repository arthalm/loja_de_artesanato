#include "produto.h"
#include <string>
#include <iostream>

static int proximoID = 1;

Produto::Produto(std::string ttl, double p): id(proximoID++), titulo(ttl), precoBase(p), idArtesao(0)
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