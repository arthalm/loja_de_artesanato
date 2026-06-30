#ifndef SISTEMALOJA_H
#define SISTEMALOJA_H

#include <vector>
#include "../usuario/usuario.h"
#include "../usuario/cliente/cliente.h"
#include "../usuario/artesao/artesao.h"
#include "../produto/produto.h"
#include "../pedido/pedido.h"

class SistemaLoja
{
private:
    std::vector<Usuario *> usuarios;
    std::vector<Produto *> catalogo;
    std::vector<Pedido *> pedidos;

    Usuario *usuarioLogado;

    // Menus
    bool menuDeslogado();
    void menuCliente();
    void menuArtesao();

    // Autenticação
    void cadastrarCliente();
    void cadastrarArtesao();
    void fazerLogin();
    void recuperarSenha();

    // Loja
    void cadastrarProduto();
    void listarCatalogo();
    void realizarVenda();

    // Cliente
    void cadastrarEndereco();

public:
    SistemaLoja();
    ~SistemaLoja();

    void iniciarSistema();
};

#endif