#ifndef CLIENTE_H
#define CLIENTE_H

#include "../usuario.h"

class Cliente : public Usuario
{
private:
    std::string end_entrega;
    double saldo_atual;

public:
    Cliente(std::string nm, std::string log, std::string c, std::string pwd, std::string end_ent, double sld_at) 
        : Usuario(nm, log, c, pwd), end_entrega(end_ent), saldo_atual(sld_at) {}

    std::string getEndereco();
    double getSaldoAtual();

    void exibirDados() override
    {
        std::cout << "=== PERFIL DO CLIENTE ===" 
                  << "\nNome: " << getNome() 
                  << "\nLogin: " << getLogin() 
                  << "\nEndereço: " << getEndereco() 
                  << "\nSaldo atual: R$ " << getSaldoAtual() << std::endl;
    }
};

#endif