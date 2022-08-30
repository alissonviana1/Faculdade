#ifndef ITRANSFORMARDADOS_H
#define ITRANSFORMARDADOS_H
#include <QString>
#include <iostream>

namespace ava {
typedef QString qs;
class ITransformarDados{

    virtual qs desmaterializar()const = 0;
    virtual void materializar(qs str) = 0;
};

}

#endif // ITRANSFORMARDADOS_H
