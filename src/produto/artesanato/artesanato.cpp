#include "artesanato.h"

Artesanato::Artesanato(std::string ttl, double pr, int tempo, bool sobEncomenda, int qtd)
    : Produto(ttl, pr, qtd), tempoProducaoDias(tempo), feitoSobEncomenda(sobEncomenda) {}

double Artesanato::calcularPreco()
{
    double taxaDiaria = 5.0;

    double preco = precoBase + (tempoProducaoDias * taxaDiaria);

    if (feitoSobEncomenda)
    {
        preco += 50.0;
    }

    return preco;
}

int Artesanato::getTempo()
{
    return tempoProducaoDias;
}

bool Artesanato::getFeitoSobEncomenda()
{
    return feitoSobEncomenda;
}