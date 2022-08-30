#include "telefone.h"

namespace ava{

QString telefone::getTelefone()const{
    QString saida;
    saida += ddi;
    saida += "(";
    saida += ddd;
    saida += ")";
    saida += numero;
    return saida;

}
void telefone::setTelefone(QString ddi, QString ddd, QString numero){
    this->ddi = ddi;
    this->ddd = ddd;
    this->numero = numero;
}
QString telefone::desmaterializar()const
{
    return (ddi + ";" + ddd + ";" + numero);
}

void telefone::materializar(qs str)
{
    QStringList dados = str.split(";");
    ddi = dados[0];
    ddd = dados[1];
    numero = dados[2];

}
}
