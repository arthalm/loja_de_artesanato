#include "cliente.h"

const Endereco &Cliente::getEndereco() const
{
    return end_entrega;
}

double Cliente::getSaldoAtual()
{
    return saldo_atual;
}

void Cliente::setEndereco(const Endereco &end)
{
    end_entrega = end;
}