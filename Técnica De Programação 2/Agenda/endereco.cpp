#include "endereco.h"

namespace ava{
typedef QString qs;
endereco::endereco(qs logradouro, qs complemento, qs cep)
{
    this->logradouro = logradouro;
    this->complemento = complemento;
    this->cep = cep;
}
qs endereco::desmaterializar()const
{
    return (logradouro + ";" + complemento + ";" + cep);
}

void endereco::materializar(qs str)
{
    QStringList dados = str.split(";");
    logradouro = dados[0];
    complemento = dados[1];
    cep = dados[2];
}

}
