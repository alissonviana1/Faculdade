#ifndef CRUD_H
#define CRUD_H
#include <cliente.h>
#include <list>

namespace ava{

class crud{

public:
    virtual void incluir(cliente &obj) const = 0;
    virtual void tirar(QString id) const = 0;
    virtual void alterar(QString ide,int coluna, QString alt) const = 0;
    virtual void alterarTelefone(QString id, QString ddi, QString ddd, QString numero)const = 0;

    virtual std::list<cliente>* listagem()const = 0;
};
}

#endif // CRUD_H
