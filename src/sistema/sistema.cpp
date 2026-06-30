#include "sistema.h"
#include "../produto/pintura/pintura.h"
#include "../produto/escultura/escultura.h"
#include "../produto/artesanato/artesanato.h"
#include "../usuario/cliente/cliente.h"
#include "../usuario/artesao/artesao.h"
#include "../gerenciador/gerenciador.h"
#include "excecoes.h"
#include <iostream>
#include <limits>
#include <regex>

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
    std::cout << "5. Meus Pedidos\n";
    std::cout << "6. Adicionar Saldo (Pix)\n";
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
    case 5:
        verMeusPedidos();
        break;
    case 6:
    {
        double valorPix;
        std::cout << "Digite o valor do deposito PIX: R$ ";
        std::cin >> valorPix;
        Cliente *c = dynamic_cast<Cliente *>(usuarioLogado);
        if (c)
        {
            c->adicionarSaldo(valorPix);
            std::cout << "-> Deposito realizado com sucesso! Novo saldo: R$ " << c->getSaldoAtual() << "\n";
        }
        break;
    }
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
    std::cout << "4. Gerenciar Pedidos\n";
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
    case 4:
        gerenciarPedidos();
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
    try {
        std::cout << "Login (E-mail): ";
        std::getline(std::cin, login);
        
        if (login.find('@') == std::string::npos) {
            throw EmailInvalidoException();
        }

        std::cout << "CPF (XXX.XXX.XXX-XX): ";
        std::getline(std::cin, cpf);
        
        std::regex padraoCpf("^\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}$");
        if (!std::regex_match(cpf, padraoCpf)) {
            throw CpfInvalidoException();
        }

        for (auto u : usuarios) {
            Cliente* c = dynamic_cast<Cliente*>(u);
            if (c != nullptr && c->getCpf() == cpf) {
                throw CpfRepetidoException();
            }
            
            Artesao* a = dynamic_cast<Artesao*>(u);
            if (a != nullptr && a->getCpf() == cpf) {
                throw CpfRepetidoException();
            }
        }

        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        
        if (senha.length() < 4) {
            throw SenhaInvalidaException();
        }

        std::cout << "Saldo Inicial (R$): ";
        std::cin >> saldo;

        usuarios.push_back(new Cliente(nome, login, cpf, senha, saldo));
        std::cout << "-> Cliente cadastrado com sucesso! Voce ja pode fazer login.\n";

    } catch (const EmailInvalidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const SenhaInvalidaException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const CpfInvalidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const CpfRepetidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    }
}

void SistemaLoja::cadastrarArtesao()
{
    std::string nome, login, cpf, senha, atelie, biografia;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n-- Cadastro de Novo Artesao --\nNome: ";
    std::getline(std::cin, nome);
    try {
        std::cout << "Login (E-mail): ";
        std::getline(std::cin, login);
        
        if (login.find('@') == std::string::npos) {
            throw EmailInvalidoException();
        }

        std::cout << "CPF (XXX.XXX.XXX-XX): ";
        std::getline(std::cin, cpf);
        
        std::regex padraoCpf("^\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}$");
        if (!std::regex_match(cpf, padraoCpf)) {
            throw CpfInvalidoException();
        }

        for (auto u : usuarios) {
            Cliente* c = dynamic_cast<Cliente*>(u);
            if (c != nullptr && c->getCpf() == cpf) {
                throw CpfRepetidoException();
            }
            
            Artesao* a = dynamic_cast<Artesao*>(u);
            if (a != nullptr && a->getCpf() == cpf) {
                throw CpfRepetidoException();
            }
        } 

        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        
        if (senha.length() < 4) {
            throw SenhaInvalidaException();
        }

        std::cout << "Nome do Atelie: ";
        std::getline(std::cin, atelie);
        std::cout << "Biografia: ";
        std::getline(std::cin, biografia);

        usuarios.push_back(new Artesao(nome, login, cpf, senha, atelie, biografia));
        std::cout << "-> Artesao cadastrado com sucesso! Voce ja pode fazer login.\n";

    } catch (const EmailInvalidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const SenhaInvalidaException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const CpfInvalidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    } catch (const CpfRepetidoException& e) {
        std::cout << "\n" << e.what() << "\n";
    }
}

void SistemaLoja::cadastrarProduto()
{
    int tipo;
    std::string titulo;
    double preco;
    int quantidade;

    std::cout << "\n-- Cadastro de Produto --\n";
    std::cout << "Tipo (1-Pintura, 2-Escultura, 3-Artesanato): ";
    std::cin >> tipo;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Titulo da Obra: ";
    std::getline(std::cin, titulo);
    std::cout << "Preco Base (R$): ";
    std::cin >> preco;
    std::cout << "Quantidade em Estoque: ";
    std::cin >> quantidade;

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

        catalogo.push_back(new Pintura(titulo, preco, tipoTinta, moldura, (Dimensao)dim, quantidade));
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

        catalogo.push_back(new Escultura(titulo, preco, material, (Peso)peso, quantidade));
    }
    else if (tipo == 3)
    {
        int tempo;
        bool encomenda;

        std::cout << "Tempo de Producao (dias): ";
        std::cin >> tempo;
        std::cout << "Feito sob Encomenda? (1-Sim, 0-Nao): ";
        std::cin >> encomenda;

        catalogo.push_back(new Artesanato(titulo, preco, tempo, encomenda, quantidade));
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
    bool algumProdutoAdicionado = false;

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
                encontrado = true;

                if (!p->removerEstoque(1))
                {
                    std::cout << "-> Produto '" << p->getTitulo() << "' sem estoque disponivel.\n";
                    break;
                }

                novoPedido->adicionarProduto(p);
                algumProdutoAdicionado = true;
                std::cout << "-> Produto '" << p->getTitulo() << "' adicionado! (Estoque restante: "
                          << p->getQuantidadeEstoque() << ")\n";
                break;
            }
        }
        if (!encontrado)
        {
            std::cout << "-> ID nao encontrado. Tente novamente.\n";
        }
    }

    double totalCompra = novoPedido->calcularTotal();
    try {
        if (clienteAtual->getSaldoAtual() < totalCompra) {
            throw SaldoInsuficienteException();
        }

        clienteAtual->descontarSaldo(totalCompra);
        //novoPedido->avancarEstado(); 
        //pedidos.push_back(novoPedido);

        std::cout << "Pedido finalizado com sucesso!\n";
        std::cout << "Comprador: " << clienteAtual->getNome() << "\n";
        std::cout << "Valor cobrado: R$ " << totalCompra << "\n";
        std::cout << "Saldo restante: R$ " << clienteAtual->getSaldoAtual() << "\n";

    } catch (const SaldoInsuficienteException& e) {
        std::cout << e.what() << "\n";
        std::cout << "Total da compra: R$ " << totalCompra << "\n";
        std::cout << "Seu saldo atual: R$ " << clienteAtual->getSaldoAtual() << "\n";
        std::cout << "Dica: Va no menu e faca um deposito via PIX.\n";
        std::cout << "Venda Cancelada.\n";

        delete novoPedido; 
    }


    if (!algumProdutoAdicionado)
    {
        std::cout << "-> Nenhum produto foi adicionado. Compra cancelada.\n";
        delete novoPedido;
        return;
    }

    // garante que o cliente tenha um endereço de entrega cadastrado.
    if (clienteAtual->getEndereco().getLogradouro().empty())
    {
        std::cout << "\nVocê ainda não possui um endereço cadastrado.\n";
        std::cout << "=== Cadastro de Endereço de Entrega ===\n";
        Endereco endereco = lerEnderecoDoTeclado();
        clienteAtual->setEndereco(endereco);
    }

    novoPedido->definirEnderecoEntrega(clienteAtual->getEndereco());
    novoPedido->avancarEstado();
    pedidos.push_back(novoPedido);

    const Endereco &e = novoPedido->getEnderecoEntrega();
    std::cout << "\nPedido finalizado com sucesso!\n";
    std::cout << "Comprador: " << clienteAtual->getNome() << "\n";
    std::cout << "Valor total da compra: R$ " << novoPedido->calcularTotal() << "\n";
    std::cout << "Sera entregue no endereço cadastrado:\n";
    std::cout << "  " << e.getLogradouro() << ", " << e.getNumero();
    if (!e.getComplemento().empty())
        std::cout << " - " << e.getComplemento();
    std::cout << "\n  " << e.getBairro() << " - " << e.getCidade() << "/" << e.getEstado()
              << " - CEP: " << e.getCEP() << "\n";
}

Endereco SistemaLoja::lerEnderecoDoTeclado()
{
    std::string destinatario;
    std::string logradouro;
    int numero;
    std::string complemento;
    std::string bairro;
    std::string cidade;
    std::string estado;
    std::string cep;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

    return Endereco(destinatario, logradouro, numero, complemento, bairro, cidade, estado, cep);
}

std::string SistemaLoja::statusParaTexto(Status s)
{
    switch (s)
    {
    case Status::RECEBIDO:
        return "Recebido";
    case Status::PROCESSANDO:
        return "Processando";
    case Status::ENVIADO:
        return "Enviado";
    case Status::EM_TRANSPORTE:
        return "Em Transporte";
    case Status::ENTREGUE:
        return "Entregue";
    }
    return "Desconhecido";
}

void SistemaLoja::cadastrarEndereco()
{
    Cliente *cliente = dynamic_cast<Cliente *>(usuarioLogado);

    if (cliente == nullptr)
    {
        std::cout << "Apenas clientes podem cadastrar endereço.\n";
        return;
    }

    std::cout << "\n=== Cadastro de Endereço ===\n";
    Endereco endereco = lerEnderecoDoTeclado();
    cliente->setEndereco(endereco);

    std::cout << "Endereço cadastrado com sucesso!\n";
}

void SistemaLoja::verMeusPedidos()
{
    Cliente *clienteAtual = dynamic_cast<Cliente *>(usuarioLogado);

    if (clienteAtual == nullptr)
    {
        std::cout << "Erro: Apenas clientes podem ver seus pedidos.\n";
        return;
    }

    std::cout << "\n-- Meus Pedidos --\n";
    bool algumPedido = false;

    for (auto ped : pedidos)
    {
        if (ped->getClienteLogin() != clienteAtual->getLogin())
            continue;

        algumPedido = true;
        const Endereco &e = ped->getEnderecoEntrega();

        std::cout << "------------------------------\n";
        std::cout << "Status: " << statusParaTexto(ped->getStatus()) << "\n";
        std::cout << "Produtos:\n";
        for (auto p : ped->getProdutos())
        {
            std::cout << "  - " << p->getTitulo() << " (R$ " << p->calcularPreco() << ")\n";
        }
        std::cout << "Total: R$ " << ped->calcularTotal() << "\n";
        std::cout << "Entrega em: " << e.getLogradouro() << ", " << e.getNumero()
                  << " - " << e.getBairro() << " - " << e.getCidade() << "/" << e.getEstado() << "\n";
    }

    if (!algumPedido)
    {
        std::cout << "Você ainda não fez nenhum pedido.\n";
    }
}

void SistemaLoja::gerenciarPedidos()
{
    std::cout << "\n-- Gerenciar Pedidos (pendentes) --\n";

    std::vector<Pedido *> pendentes;
    for (auto ped : pedidos)
    {
        if (ped->getStatus() != Status::ENTREGUE)
        {
            pendentes.push_back(ped);
        }
    }

    if (pendentes.empty())
    {
        std::cout << "Nenhum pedido pendente no momento.\n";
        return;
    }

    for (size_t i = 0; i < pendentes.size(); i++)
    {
        Pedido *ped = pendentes[i];
        std::cout << i + 1 << ". Cliente: " << ped->getClienteLogin()
                  << " | Status: " << statusParaTexto(ped->getStatus())
                  << " | Total: R$ " << ped->calcularTotal() << "\n";
    }

    std::cout << "Digite o numero do pedido para avançar o status (0 para cancelar): ";
    int escolha;
    std::cin >> escolha;

    if (escolha <= 0 || static_cast<size_t>(escolha) > pendentes.size())
    {
        std::cout << "Operação cancelada.\n";
        return;
    }

    Pedido *selecionado = pendentes[escolha - 1];
    selecionado->avancarEstado();

    std::cout << "-> Pedido atualizado! Novo status: " << statusParaTexto(selecionado->getStatus()) << "\n";
    if (selecionado->getStatus() == Status::ENTREGUE)
    {
        std::cout << "-> Pedido entregue! Ele saiu da lista de pedidos pendentes.\n";
    }
}