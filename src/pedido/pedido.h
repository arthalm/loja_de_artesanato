#ifndef PEDIDO_H
#define PEDIDO_H

#include "../usuario/cliente/cliente.h"
#include "../produto/produto.h"
#include <vector>

enum class Status
{
    RECEBIDO,
    PROCESSANDO,
    ENVIADO,
    EM_TRANSPORTE,
    ENTREGUE
};

class Pedido
{
    Cliente cliente;
    std::vector<Produto *> produtos;
    Status statusAtual;
    Endereco enderecoEntrega;

public:
    Pedido(Cliente c) : cliente(c), statusAtual(Status::RECEBIDO), enderecoEntrega("", "", 0, "", "", "", "", "") {}

    void adicionarProduto(Produto *p);

    std::string getClienteLogin();

    Status getStatus();

    std::vector<Produto *> getProdutos();

    void avancarEstado();

    double calcularTotal() const;

    void definirEnderecoEntrega(const Endereco &end);
    const Endereco &getEnderecoEntrega() const;
};

#endif