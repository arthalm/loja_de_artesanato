#include "artesanato.h"

Artesanato::Artesanato(std::string ttl, double pr, int tempo, bool sobEncomenda)
: Produto(ttl, pr), tempoProducaoDias(tempo), feitoSobEncomenda(sobEncomenda) {}

double Artesanato::calcularPreco()
{
    double taxaDiaria = 5.0;

    double preco = precoBase + (tempoProducaoDias * taxaDiaria);

    if (feitoSobEncomenda)
    {preco += 50.0;}

    return preco;
}