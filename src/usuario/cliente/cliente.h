#ifndef CLIENTE_H
#define CLIENTE_H

<<<<<<< HEAD
#include "usuario.h"
=======
#include "../usuario.h"
>>>>>>> jordson

class Cliente : public Usuario
{
private:
<<<<<<< HEAD
    // std::Endereco end_entrega;

=======
>>>>>>> jordson
    std::string end_entrega;
    double saldo_atual;

public:
<<<<<<< HEAD
    Cliente(std::string nm, std::string log, std::string end_ent, double sld_at) : Usuario(nm, log), end_entrega(end_ent), saldo_atual(sld_at) {}

    // Endereco getEndereco();
=======
    Cliente(std::string nm, std::string log, std::string c, std::string pwd, std::string end_ent, double sld_at) 
        : Usuario(nm, log, c, pwd), end_entrega(end_ent), saldo_atual(sld_at) {}
>>>>>>> jordson

    std::string getEndereco();
    double getSaldoAtual();

    void exibirDados() override
    {
<<<<<<< HEAD
        std::cout << "===DADOS=DO=CLIENTE===" << "\nNome: " << Cliente::getNome() << "\nLogin: " << Cliente::getLogin() << "\nEndereço: " << Cliente::getEndereco() << "\nSaldo atual: " << Cliente::getSaldoAtual() << std::endl;
    }

    void cadastrarEndereco()
    {
=======
        std::cout << "=== PERFIL DO CLIENTE ===" 
                  << "\nNome: " << getNome() 
                  << "\nLogin: " << getLogin() 
                  << "\nEndereço: " << getEndereco() 
                  << "\nSaldo atual: R$ " << getSaldoAtual() << std::endl;
>>>>>>> jordson
    }
};

#endif