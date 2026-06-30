#include "sistema.h"
#include "../produto/pintura/pintura.h"
#include "../produto/escultura/escultura.h"
#include "../produto/artesanato/artesanato.h"
#include "../usuario/cliente/cliente.h"
#include "../usuario/artesao/artesao.h"
#include "../gerenciador/gerenciador.h"
#include <iostream>
#include <limits>

SistemaLoja::SistemaLoja()
{
    usuarioLogado = nullptr;
    GerenciadorArquivos ga;
    ga.carregarDados(usuarios, catalogo, pedidos);
}

SistemaLoja::~SistemaLoja()
{
    GerenciadorArquivos ga;
    ga.salvarDados(usuarios, catalogo, pedidos);
    for (auto u : usuarios)
        delete u;
    for (auto p : catalogo)
        delete p;
    for (auto ped : pedidos)
        delete ped;
}

void SistemaLoja::iniciarSistema()
{
    std::cout << "  Bem-vindo ao Soul Arte\n";

    bool rodando = true;
    while (rodando)
    {
        if (usuarioLogado == nullptr)
        {
            rodando = menuDeslogado();
        }
        else
        {
            if (dynamic_cast<Cliente *>(usuarioLogado) != nullptr)
            {
                menuCliente();
            }
            else if (dynamic_cast<Artesao *>(usuarioLogado) != nullptr)
            {
                menuArtesao();
            }
        }
    }
}

bool SistemaLoja::menuDeslogado()
{
    int opcao = -1;
    std::cout << "\n Tela de Inicial\n";
    std::cout << "1. Fazer Login\n";
    std::cout << "2. Cadastrar novo Cliente\n";
    std::cout << "3. Cadastrar novo Artesao\n";
    std::cout << "4. Esqueci minha senha\n";
    std::cout << "0. Encerrar Sistema\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        fazerLogin();
        break;
    case 2:
        cadastrarCliente();
        break;
    case 3:
        cadastrarArtesao();
        break;
    case 4:
        recuperarSenha();
        break;
    case 0:
        return false;
    default:
        std::cout << "Opcao invalida!\n";
    }
    return true;
}

void SistemaLoja::menuCliente()
{
    int opcao = -1;
    std::cout << "\n Tela do Cliente: " << usuarioLogado->getNome() << " \n";
    std::cout << "1. Ver Catalogo de Produtos\n";
    std::cout << "2. Comprar Produtos\n";
    std::cout << "3. Meu Perfil\n";
    std::cout << "4. Meu Endereço\n";
    std::cout << "0. Fazer Logout\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        listarCatalogo();
        break;
    case 2:
        realizarVenda();
        break;
    case 3:
        usuarioLogado->exibirDados();
        break;
    case 4:
        cadastrarEndereco();
        break;
    case 0:
        usuarioLogado = nullptr;
        std::cout << "Logout realizado com sucesso!\n";
        break;
    default:
        std::cout << "Opcao invalida!\n";
    }
}

void SistemaLoja::menuArtesao()
{
    int opcao = -1;
    std::cout << "\n Tela do Artesão: " << usuarioLogado->getNome() << " \n";
    std::cout << "1. Cadastrar Novo Produto\n";
    std::cout << "2. Ver Catalogo Geral\n";
    std::cout << "3. Meu Perfil\n";
    std::cout << "0. Fazer Logout\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;

    switch (opcao)
    {
    case 1:
        cadastrarProduto();
        break;
    case 2:
        listarCatalogo();
        break;
    case 3:
        usuarioLogado->exibirDados();
        break;
    case 0:
        usuarioLogado = nullptr;
        std::cout << "Logout realizado com sucesso!\n";
        break;
    default:
        std::cout << "Opcao invalida!\n";
    }
}

void SistemaLoja::fazerLogin()
{
    std::string log, pwd;
    std::cout << "\n LOGIN \n";
    std::cout << "Usuario (Login): ";
    std::cin >> log;
    std::cout << "Senha: ";
    std::cin >> pwd;

    for (auto u : usuarios)
    {
        if (u->getLogin() == log && u->getSenha() == pwd)
        {
            usuarioLogado = u;
            std::cout << "\n-> Acesso bem sucedido! Bem-vindo(a), " << u->getNome() << ".\n";
            return;
        }
    }
    std::cout << "-> Acesso negado. Usuario ou senha incorretos!\n";
}

void SistemaLoja::recuperarSenha()
{
    std::string log;
    std::cout << "\n-- Recuperacao de Senha --\n";
    std::cout << "Digite seu Login: ";
    std::cin >> log;

    for (auto u : usuarios)
    {
        if (u->getLogin() == log)
        {
            std::cout << "-> A senha vinculada a este login eh: " << u->getSenha() << "\n";
            return;
        }
    }
    std::cout << "-> Login nao encontrado no sistema.\n";
}

void SistemaLoja::cadastrarCliente()
{
    std::string nome, login, cpf, senha;
    double saldo;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n-- Cadastro de Novo Cliente --\nNome: ";
    std::getline(std::cin, nome);
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "CPF: ";
    std::getline(std::cin, cpf);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);
    std::cout << "Saldo Inicial (R$): ";
    std::cin >> saldo;

    usuarios.push_back(new Cliente(nome, login, cpf, senha, saldo));
    std::cout << "-> Cliente cadastrado com sucesso! Voce ja pode fazer login.\n";
}

void SistemaLoja::cadastrarArtesao()
{
    std::string nome, login, cpf, senha, atelie, biografia;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n-- Cadastro de Novo Artesao --\nNome: ";
    std::getline(std::cin, nome);
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "CPF: ";
    std::getline(std::cin, cpf);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);
    std::cout << "Nome do Atelie: ";
    std::getline(std::cin, atelie);
    std::cout << "Biografia: ";
    std::getline(std::cin, biografia);

    usuarios.push_back(new Artesao(nome, login, cpf, senha, atelie, biografia));
    std::cout << "-> Artesao cadastrado com sucesso! Voce ja pode fazer login.\n";
}

void SistemaLoja::cadastrarProduto()
{
    int tipo;
    std::string titulo;
    double preco;

    std::cout << "\n-- Cadastro de Produto --\n";
    std::cout << "Tipo (1-Pintura, 2-Escultura, 3-Artesanato): ";
    std::cin >> tipo;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Titulo da Obra: ";
    std::getline(std::cin, titulo);
    std::cout << "Preco Base (R$): ";
    std::cin >> preco;

    if (tipo == 1)
    {
        std::string tipoTinta;
        bool moldura;
        int dim;

        std::cin.ignore();
        std::cout << "Tipo de Tinta: ";
        std::getline(std::cin, tipoTinta);
        std::cout << "Possui Moldura? (1-Sim, 0-Nao): ";
        std::cin >> moldura;
        std::cout << "Dimensao (0-Pequeno, 1-Medio, 2-Grande): ";
        std::cin >> dim;

        catalogo.push_back(new Pintura(titulo, preco, tipoTinta, moldura, (Dimensao)dim));
    }
    else if (tipo == 2)
    {
        std::string material;
        int peso;

        std::cin.ignore();
        std::cout << "Material: ";
        std::getline(std::cin, material);
        std::cout << "Peso (0-Leve, 1-Medio, 2-Pesado): ";
        std::cin >> peso;

        catalogo.push_back(new Escultura(titulo, preco, material, (Peso)peso));
    }
    else if (tipo == 3)
    {
        int tempo;
        bool encomenda;

        std::cout << "Tempo de Producao (dias): ";
        std::cin >> tempo;
        std::cout << "Feito sob Encomenda? (1-Sim, 0-Nao): ";
        std::cin >> encomenda;

        catalogo.push_back(new Artesanato(titulo, preco, tempo, encomenda));
    }
    std::cout << "-> Produto adicionado ao catalogo com sucesso!\n";
}

void SistemaLoja::listarCatalogo()
{
    std::cout << "\n-- Catalogo de Produtos --\n";
    if (catalogo.empty())
    {
        std::cout << "Nenhum produto cadastrado no momento.\n";
        return;
    }

    for (auto p : catalogo)
    {
        p->exibirDados();
        std::cout << " | Preco Final: R$ " << p->calcularPreco() << "\n";
    }
}

void SistemaLoja::realizarVenda()
{
    Cliente *clienteAtual = dynamic_cast<Cliente *>(usuarioLogado);

    if (clienteAtual == nullptr)
    {
        std::cout << "Erro: Apenas clientes podem realizar compras.\n";
        return;
    }

    if (catalogo.empty())
    {
        std::cout << "Erro: O catalogo de produtos esta vazio!\n";
        return;
    }

    Pedido *novoPedido = new Pedido(*clienteAtual);
    int idBusca = -1;

    listarCatalogo();

    std::cout << "\n-- Carrinho de Compras --\n";
    while (true)
    {
        std::cout << "Digite o ID do produto para adicionar (0 para finalizar a compra): ";
        std::cin >> idBusca;

        if (idBusca == 0)
            break;

        bool encontrado = false;
        for (auto p : catalogo)
        {
            if (p->getID() == idBusca)
            {
                novoPedido->adicionarProduto(p);
                std::cout << "-> Produto '" << p->getTitulo() << "' adicionado!\n";
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            std::cout << "-> ID nao encontrado. Tente novamente.\n";
        }
    }

    novoPedido->avancarEstado();
    pedidos.push_back(novoPedido);

    std::cout << "Pedido finalizado com sucesso!\n";
    std::cout << "Comprador: " << clienteAtual->getNome() << "\n";
    std::cout << "Valor total da compra: R$ " << novoPedido->calcularTotal() << "\n";
}

void SistemaLoja::cadastrarEndereco()
{
    Cliente *cliente = dynamic_cast<Cliente *>(usuarioLogado);

    if (cliente == nullptr)
    {
        std::cout << "Apenas clientes podem cadastrar endereço.\n";
        return;
    }

    std::string destinatario;
    std::string logradouro;
    int numero;
    std::string complemento;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n=== Cadastro de Endereço ===\n";
    std::cout << "Destinatário: ";
    std::getline(std::cin, destinatario);
    std::cout << "Logradouro: ";
    std::getline(std::cin, logradouro);
    std::cout << "Número: ";
    std::cin >> numero;
    std::cin.ignore();
    std::cout << "Complemento: ";
    std::getline(std::cin, complemento);
    std::cout << "Bairro: ";
    std::getline(std::cin, bairro);
    std::cout << "Cidade: ";
    std::getline(std::cin, cidade);
    std::cout << "Estado: ";
    std::getline(std::cin, estado);
    std::cout << "CEP: ";
    std::getline(std::cin, cep);

    Endereco endereco(
        destinatario,
        logradouro,
        numero,
        complemento,
        bairro,
        cidade,
        estado,
        cep);

    cliente->setEndereco(endereco);

    std::cout << "Endereço cadastrado com sucesso!\n";
}