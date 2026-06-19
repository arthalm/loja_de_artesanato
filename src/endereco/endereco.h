#ifndef ENDERECO_H
#define ENDERECO_H
  
#include <string>
  
class Endereco 
{
    std::string destinatario;
    std::string logradouro;
    int numero;
    std::string complemento;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;
};

#endif