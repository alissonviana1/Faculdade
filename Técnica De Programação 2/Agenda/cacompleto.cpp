#include "cacompleto.h"
#include <QString>
#include <QStringList>

namespace ava {

CaCompleto::CaCompleto():
    nome(""),
    id("")
{
}
CaCompleto::CaCompleto(QString nome, QString id)
{
    this->nome = nome;
    this->id = id;
}
QString CaCompleto::desmaterializar()const
{
    return (nome + ";" + id);
}
void CaCompleto::materializar(QString str)
{

    QStringList dados = str.split(";");
    nome = dados[0];
    id = dados[1];

}

}
