#include "produto.h"
#include <string>

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