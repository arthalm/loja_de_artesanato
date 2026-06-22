#include "artesanato.h"

Artesanato::Artesanato(std::string ttl, double pr, int tempo, bool sobEncomenda)
: Produto(ttl, pr), tempoProducaoDias(tempo), feitoSobEncomenda(sobEncomenda) {}

double Artesanato::calcularFrete()
{
    //taxa base = 15
    //adicional = se for encomenda adiciona uma taxa de 12
    //será que da pra relacionar o valor com tempo? uma taxa * estimativa de dias 
    double freteBase = 15;
    
    if (feitoSobEncomenda) {
        return freteBase + 12; 
    }
    
    return freteBase;
}