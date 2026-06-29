#ifndef ARTESAO_H
#define ARTESAO_H

#include "usuario.h"

class Artesao : public Usuario
{
private:
    std::string nome_atelie;
    std::string biografia;

public:
    Artesao(std::string nm, std::string log, std::string nm_ate, std::string bio) : Usuario(nm, log), nome_atelie(nm_ate), biografia(bio) {}

    std::string getNomeAtelie();
    std::string getBiografia();

    void exibirDados() override
    {
        std::cout << "===DADOS=DO=ARTESÃO===" << "\nNome: " << Artesao::getNome() << "\nLogin: " << Artesao::getLogin() << "\nNome do ateliê: " << Artesao::getNomeAtelie() << "\nBiografia: " << Artesao::getBiografia() << std::endl;
    }

    void cadastrarProduto()
    {
    }
};

#endif