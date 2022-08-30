#ifndef TRANSFORMARCATEGORIA_H
#define TRANSFORMARCATEGORIA_H
#include <QString>
#include <iostream>

namespace ava {
typedef QString qs;
class transformarcategoria{

    virtual qs desmaterializar()const = 0;
    virtual void materializar(qs str) = 0;
};

}


#endif // TRANSFORMARCATEGORIA_H
