#ifndef ARTESAO_H
#define ARTESAO_H

<<<<<<< HEAD
#include "usuario.h"
=======
#include "../usuario.h"
>>>>>>> jordson

class Artesao : public Usuario
{
private:
    std::string nome_atelie;
    std::string biografia;

public:
<<<<<<< HEAD
    Artesao(std::string nm, std::string log, std::string nm_ate, std::string bio) : Usuario(nm, log), nome_atelie(nm_ate), biografia(bio) {}
=======
    Artesao(std::string nm, std::string log, std::string c, std::string pwd, std::string nm_ate, std::string bio) 
        : Usuario(nm, log, c, pwd), nome_atelie(nm_ate), biografia(bio) {}
>>>>>>> jordson

    std::string getNomeAtelie();
    std::string getBiografia();

    void exibirDados() override
    {
<<<<<<< HEAD
        std::cout << "===DADOS=DO=ARTESÃO===" << "\nNome: " << Artesao::getNome() << "\nLogin: " << Artesao::getLogin() << "\nNome do ateliê: " << Artesao::getNomeAtelie() << "\nBiografia: " << Artesao::getBiografia() << std::endl;
    }

    void cadastrarProduto()
    {
=======
        std::cout << "=== PERFIL DO ARTESÃO ===" 
                  << "\nNome: " << getNome() 
                  << "\nLogin: " << getLogin() 
                  << "\nAteliê: " << getNomeAtelie() 
                  << "\nBio: " << getBiografia() << std::endl;
>>>>>>> jordson
    }
};

#endif