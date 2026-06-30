#include "pedido.h"

void Pedido::adicionarProduto(Produto *p)
{
    produtos.push_back(p);
}

void Pedido::avancarEstado()
{
    switch (statusAtual)
    {
    case Status::RECEBIDO:
        statusAtual = Status::PROCESSANDO;
        break;
    case Status::PROCESSANDO:
        statusAtual = Status::ENVIADO;
        break;
    case Status::ENVIADO:
        statusAtual = Status::EM_TRANSPORTE;
        break;
    case Status::EM_TRANSPORTE:
        statusAtual = Status::ENTREGUE;
        break;
    case Status::ENTREGUE:
        break;
    }
}

double Pedido::calcularTotal() const
{
    double total = 0;
    for (int i = 0; i < produtos.size(); i++)
    {
        total += produtos[i]->calcularPreco();
    }

    return total;
}