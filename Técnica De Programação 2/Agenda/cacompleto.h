#ifndef CACOMPLETO_H
#define CACOMPLETO_H
#include <transformarcategoria.h>
#include <list>
#include <QString>
namespace ava {

class CaCompleto: public transformarcategoria
{
private:
    QString nome;
    QString id;
public:
    CaCompleto(QString nome,QString id);
    CaCompleto();
    void setId(QString id){this->id = id;}
    QString getId()const{return id;}

    void setNome(QString nome){this->nome = nome;}
    QString getNome()const{return nome;}
    //reescrever
    QString desmaterializar()const;
    void materializar(QString str);


};
}
#endif // CACOMPLETO_H
