#ifndef ESCULTURA_H
#define ESCULTURA_H

#include "../produto.h"
#include <string>

enum class Peso
{
    LEVE, MEDIO, PESADO
};

class Escultura : public Produto
{
    std::string material;
    Peso pesoTotal;

public:
    Escultura(std::string ttl, double pr, std::string mat, Peso peso);
    
    double calcularPreco() override;

    std::string getMaterial();
    Peso getPeso();
};

#endif