#ifndef CATE_H
#define CATE_H
#include <crud2.h>
#include <QString>
#include <fstream>
#include <cacompleto.h>
namespace ava {

class cate: public crud2
{
private:
     QString nomeDoArquivoNoDisco;
public:
    cate(QString nome);


    virtual void incluir(CaCompleto &no) const;
    virtual void tirar(QString id) const;
    virtual std::list<CaCompleto>* listagem()const;
};
}
#endif // CATE_H
