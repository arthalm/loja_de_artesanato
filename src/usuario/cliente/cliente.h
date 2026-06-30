#ifndef CLIENTE_H
#define CLIENTE_H

#include "../usuario.h"
#include "../../endereco/endereco.h"

class Cliente : public Usuario
{
private:
    Endereco end_entrega;
    double saldo_atual;

public:
    Cliente(std::string nm, std::string log, std::string c, std::string pwd, double sld_at)
        : Usuario(nm, log, c, pwd), end_entrega("", "", 0, "", "", "", "", ""), saldo_atual(sld_at) {}

    const Endereco &getEndereco() const;
    double getSaldoAtual();
    void setEndereco(const Endereco &end);
    void exibirDados() override
    {
        const Endereco &e = getEndereco();

        std::cout << "=== PERFIL DO CLIENTE ==="
                  << "\nNome: " << getNome()
                  << "\nLogin: " << getLogin()
                  << "\nDestinatário: " << e.getDestinatario()
                  << "\nLogradouro: " << e.getLogradouro()
                  << ", " << e.getNumero()
                  << "\nComplemento: " << e.getComplemento()
                  << "\nBairro: " << e.getBairro()
                  << "\nCidade: " << e.getCidade()
                  << "\nEstado: " << e.getEstado()
                  << "\nCEP: " << e.getCEP()
                  << "\nSaldo atual: R$ " << getSaldoAtual() << std::endl;
    }

    void adicionarSaldo(double valor);
    void descontarSaldo(double valor);
};

#endif