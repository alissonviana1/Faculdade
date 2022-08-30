#ifndef ENDERECO_H
#define ENDERECO_H
#include <QString>
#include <itransformardados.h>
#include <QStringList>

namespace ava{
typedef QString qs;
class endereco: public ITransformarDados
{
private:
    qs logradouro;
    qs complemento;
    qs cep;
public:
    endereco():logradouro(""),complemento(""), cep(""){}
    endereco(qs logradouro, qs complemento, qs cep);
    qs getLogradouro()const{return logradouro;}
    qs getComplemento()const{return complemento;}
    qs getCep()const{return cep;}
    void setLogradouro(qs logradouro){this->logradouro = logradouro;}
    void setComplemento(qs complemento){this->complemento = complemento;}
    void setCep(qs cep){this->cep = cep;}
    //reescrevendo da interface
    qs desmaterializar() const;
    void materializar(qs str);

};
}
#endif // ENDERECO_H
