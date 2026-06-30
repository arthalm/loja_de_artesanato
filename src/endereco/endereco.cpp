#include "endereco.h"

std::string Endereco::getDestinatario() const
{
    return destinatario;
}

std::string Endereco::getLogradouro() const
{
    return logradouro;
}

int Endereco::getNumero() const
{
    return numero;
}

std::string Endereco::getComplemento() const
{
    return complemento;
}

std::string Endereco::getBairro() const
{
    return bairro;
}

std::string Endereco::getCidade() const
{
    return cidade;
}

std::string Endereco::getEstado() const
{
    return estado;
}

std::string Endereco::getCEP() const
{
    return cep;
}
