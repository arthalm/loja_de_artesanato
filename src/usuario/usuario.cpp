#include "usuario.h"
<<<<<<< HEAD
#include <string>
#include <iostream>

Usuario::Usuario(std::string nm, std::string c): nome(nm), cpf(c){}

std::string Usuario::getNome()
{return nome;}

std::string Usuario::getCPF()
{return cpf;}

void Usuario::exibirDados()
{
    std::cout << nome << " (" << cpf << ")";
}
=======

std::string Usuario::getNome()
{
    return std::string();
}
>>>>>>> arthur
