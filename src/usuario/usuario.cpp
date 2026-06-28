#include "usuario.h"

std::string Usuario::getNome()
{
    return nome;
}

std::string Usuario::getCPF()
{
    return cpf;
}

void Usuario::exibirDados()
{
    std::cout << nome << " (" << cpf << ")\n";
}
