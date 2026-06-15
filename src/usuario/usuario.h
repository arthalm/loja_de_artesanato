#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario
{
    std::string nome;
    std::string login;
    // std::Endereco endereco

public:
    Usuario() {};

    std::string getNome();
};

#endif