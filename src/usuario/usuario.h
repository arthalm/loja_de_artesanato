#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario
{
protected:
    std::string nome;
    std::string login;
    std::string cpf;
    std::string senha;

public:
    Usuario(std::string nm, std::string log, std::string c, std::string pwd)
        : nome(nm), login(log), cpf(c), senha(pwd) {};

    std::string getNome();
    std::string getLogin();
    std::string getCpf();
    std::string getSenha();
    void setSenha(std::string novaSenha);

    virtual void exibirDados() = 0;
    virtual ~Usuario() {};
};

#endif