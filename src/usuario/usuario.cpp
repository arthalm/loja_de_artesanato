#include "usuario.h"

std::string Usuario::getNome() { return nome; }
std::string Usuario::getLogin() { return login; }
std::string Usuario::getCpf() { return cpf; }
std::string Usuario::getSenha() { return senha; }

void Usuario::setSenha(std::string novaSenha)
{
    senha = novaSenha;
}

void Usuario::exibirDados()
{
    std::cout << nome << " (" << cpf << ")";
}
