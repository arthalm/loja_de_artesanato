#ifndef ESCULTURA_H
#define ESCULTURA_H

#include "../produto.h"
#include <string>

class Escultura : public Produto
{
    std::string material;
    double pesoTotal;

public:
    Escultura(std::string ttl, double pr, std::string mat, double peso);
    
    double calcularFrete() override;
};

#endif