#ifndef ARTESAO_H
#define ARTESAO_H

#include "usuario.h"

std::ostream &operator<<(std::ostream &os, Artesao &c)
{
    
}

class Artesao : public Usuario
{
private:
    std::string nome_atelie;
    std::string biografia;

public:
    Artesao(std::string nm, std::string log, std::string nm_ate, std::string bio) : Usuario(nm, log), nome_atelie(nm_ate), biografia(bio)  {}

    void exibirDados() override
    {
    }
};

#endif