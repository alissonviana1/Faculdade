#ifndef CRUD2_H
#define CRUD2_H
#include <QString>
#include <list>
#include <cacompleto.h>
#include <fstream>

namespace ava{

class crud2{

public:




    virtual void incluir(CaCompleto &no) const = 0;
    virtual void tirar(QString id) const = 0;
    virtual std::list<CaCompleto>* listagem()const = 0;
};

}


#endif // CRUD2_H
