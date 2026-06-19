#include "pintura.h"

Pintura::Pintura(std::string ttl, double pr, std::string ttinta, bool pmol, Dimensao tq)
:Produto(ttl, pr), tipoTinta(ttinta), possuiMoldura(pmol), tamanhoQuadro(tq){}

double Pintura::calcularFrete()
{
    //taxa base = 10
    //adicional = dimensao (0, 1 ou 2) * 5
    return 10 + tamanhoQuadro * 5;
}