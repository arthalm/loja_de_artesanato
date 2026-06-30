#ifndef PINTURA_H
#define PINTURA_H

#include "../produto.h"
#include <string>

enum Dimensao
{
    PEQUENO,
    MEDIO,
    GRANDE
};

class Pintura : public Produto
{
    std::string tipoTinta;
    bool possuiMoldura;
    Dimensao tamanhoQuadro;

public:
    Pintura(std::string ttl, double pr, std::string ttinta, bool pmol, Dimensao tq, int qtd = 0);

    double calcularPreco() override;

    std::string getTipoTinta();
    bool getPossuiMoldura();
    Dimensao getTamanho();
};

#endif