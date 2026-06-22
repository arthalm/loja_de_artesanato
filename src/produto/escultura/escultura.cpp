#include "escultura.h"

Escultura::Escultura(std::string ttl, double pr, std::string mat, double peso)
: Produto(ttl, pr), material(mat), pesoTotal(peso) {}

double Escultura::calcularFrete()
{
    //taxa base = 20
    //adicional = peso * 4.50
    return 20 + (pesoTotal * 4.50);
}