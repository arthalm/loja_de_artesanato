#include "produto.h"
#include <string>
#include <iostream>

int Produto::proximoID = 0;

Produto::Produto(std::string ttl, double p): titulo(ttl), precoBase(p)
{id = proximoID++;}

int Produto::getID()
{return id;}

std::string Produto::getTitulo()
{return titulo;}

double Produto::getPreco()
{return precoBase;}

int Produto::getIDartesao()
{return idArtesao;}

void Produto::setProximoID(int valor) 
{proximoID = valor;}

void Produto::exibirDados()
{
    std::cout << titulo << " (#" << id << ") - R$ " << precoBase; 
}