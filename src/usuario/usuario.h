#ifndef USUARIO_H
#define USUARIO_H

#include <string>
<<<<<<< HEAD

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

=======
#include <iostream>

class Usuario
{
    std::string nome;
    std::string login;
    // std::Endereco endereco

public:
    Usuario() {};

    std::string getNome();
>>>>>>> arthur
};

#endif