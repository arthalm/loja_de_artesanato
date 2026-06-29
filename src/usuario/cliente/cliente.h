#ifndef CLIENTE_H
#define CLIENTE_H

#include "usuario.h"

class Cliente : public Usuario
{
private:
    // std::Endereco end_entrega;

    std::string end_entrega;
    double saldo_atual;

public:
    Cliente(std::string nm, std::string log, std::string end_ent, double sld_at) : Usuario(nm, log), end_entrega(end_ent), saldo_atual(sld_at) {}

    // Endereco getEndereco();

    std::string getEndereco();
    double getSaldoAtual();

    void exibirDados() override
    {
        std::cout << "===DADOS=DO=CLIENTE===" << "\nNome: " << Cliente::getNome() << "\nLogin: " << Cliente::getLogin() << "\nEndereço: " << Cliente::getEndereco() << "\nSaldo atual: " << Cliente::getSaldoAtual() << std::endl;
    }

    void cadastrarEndereco()
    {
    }
};

#endif