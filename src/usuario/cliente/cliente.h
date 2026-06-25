#ifndef CLIENTE_H
#define CLIENTE_H

#include "usuario.h"

std::ostream &operator<<(std::ostream &os, Cliente &c)
{
    
}

class Cliente : public Usuario
{
private:
    std::string end_entrega;
    double saldo_atual;

public:
    Cliente(std::string nm, std::string log, std::string end_ent, double sld_at) : Usuario(nm, log), end_entrega(end_ent), saldo_atual(sld_at) {}

    void exibirDados() override
    {
    }
};

#endif