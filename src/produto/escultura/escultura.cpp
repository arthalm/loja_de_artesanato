#include "escultura.h"

Escultura::Escultura(std::string ttl, double pr, std::string mat, Peso peso)
    : Produto(ttl, pr), material(mat), pesoTotal(peso) {}

double Escultura::calcularPreco()
{
    double multiplicador = 1.0;

    switch (pesoTotal)
    {
    case Peso::LEVE:
        multiplicador = 1.10;
        break;
    case Peso::MEDIO:
        multiplicador = 1.25;
        break;
    case Peso::PESADO:
        multiplicador = 1.50;
        break;
    }

    return precoBase * multiplicador;
}

std::string Escultura::getMaterial()
{
    return material;
}

Peso Escultura::getPeso()
{
    return pesoTotal;
}