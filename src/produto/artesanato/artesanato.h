#ifndef ARTESANATO_H
#define ARTESANATO_H

#include "../produto.h"
#include <string>

class Artesanato : public Produto
{
    int tempoProducaoDias;
    bool feitoSobEncomenda;

public:
    Artesanato(std::string ttl, double pr, int tempo, bool sobEncomenda);
    
    double calcularFrete() override;
};

#endif