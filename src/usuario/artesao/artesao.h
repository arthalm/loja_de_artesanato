#ifndef ARTESAO_H
#define ARTESAO_H

#include "../usuario.h"

class Artesao : public Usuario
{
private:
    std::string nome_atelie;
    std::string biografia;

public:
    Artesao(std::string nm, std::string log, std::string c, std::string pwd, std::string nm_ate, std::string bio) 
        : Usuario(nm, log, c, pwd), nome_atelie(nm_ate), biografia(bio) {}

    std::string getNomeAtelie();
    std::string getBiografia();

    void exibirDados() override
    {
        std::cout << "=== PERFIL DO ARTESÃO ===" 
                  << "\nNome: " << getNome() 
                  << "\nLogin: " << getLogin() 
                  << "\nAteliê: " << getNomeAtelie() 
                  << "\nBio: " << getBiografia() << std::endl;
    }
};

#endif