#include "produto.h"
#include <string>

Produto::Produto(std::string ttl, double p): titulo(ttl), preco(p)
{id = proximoID++;}

std::string Produto::getTitulo()
{return titulo;}

double Produto::getPreco()
{return preco;}