#ifndef EXCECOES_H
#define EXCECOES_H

#include <exception>

class SaldoInsuficienteException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Erro: Saldo insuficiente para finalizar a compra!";
    }
};

class EmailInvalidoException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Erro: O Login deve ser um e-mail valido (precisa conter '@'). Cadastro cancelado!";
    }
};

class SenhaInvalidaException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Erro: A senha deve ter pelo menos 4 caracteres. Cadastro cancelado!";
    }
};

class CpfInvalidoException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Erro: O CPF deve seguir o formato exato XXX.XXX.XXX-XX. Cadastro cancelado!";
    }
};

class CpfRepetidoException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Erro: Este CPF ja esta cadastrado no sistema. Cadastro cancelado!";
    }
};

#endif