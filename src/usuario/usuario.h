#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario
{
protected:
    std::string nome;
    std::string login;

public:
    Usuario(std::string nm, std::string log) : nome(nm), login(log) {};

    virtual void exibirDados() = 0;

    virtual ~Usuario() {};
};

#endif