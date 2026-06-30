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

void Cliente::adicionarSaldo(double valor)
{
    if (valor > 0)
        saldo_atual += valor;
}

void Cliente::descontarSaldo(double valor)
{

    if (valor > 0 && valor <= saldo_atual)
        saldo_atual -= valor;
}