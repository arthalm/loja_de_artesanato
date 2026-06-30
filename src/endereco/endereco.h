#ifndef ENDERECO_H
#define ENDERECO_H
  
#include <string>
  
class Endereco 
{
    private:
    std::string destinatario;
    std::string logradouro;
    int numero;
    std::string complemento;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;

    public:
    Endereco(std::string dest, std::string logr, int num, std::string comp, std::string bair, std::string cid, std::string est, std::string c) : destinatario(dest), logradouro(logr), numero(num), complemento(comp), bairro(bair), cidade(cid), estado(est), cep(c) {}

    std::string getDestinatario() const;
    std::string getLogradouro() const;
    int getNumero() const;
    std::string getComplemento() const;
    std::string getBairro() const;
    std::string getCidade() const;
    std::string getEstado() const;
    std::string getCEP() const;

    virtual ~Endereco() {};
};

#endif