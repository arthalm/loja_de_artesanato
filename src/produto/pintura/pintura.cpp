#include "pintura.h"

Pintura::Pintura(std::string ttl, double pr, std::string ttinta, bool pmol, Dimensao tq)
:Produto(ttl, pr), tipoTinta(ttinta), possuiMoldura(pmol), tamanhoQuadro(tq){}

double Pintura::calcularPreco()
{
    if(possuiMoldura)
    {
        return precoBase + (precoBase * 0.2);
    }
    return precoBase;
}