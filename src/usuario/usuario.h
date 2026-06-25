#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario
{
protected:
    std::string nome;
    std::string cpf;

public:
    Usuario(std::string nm, std::string c);

    std::string getNome();
    std::string getCPF();

    void exibirDados();

};

#endif