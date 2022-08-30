#ifndef TELEFONE_H
#define TELEFONE_H
#include <QString>
#include <itransformardados.h>
#include <QStringList>

namespace ava{
class telefone:public ITransformarDados
{
private:
    QString ddi;
    QString ddd;
    QString numero;
public:
    telefone():ddi(""),ddd(""),numero(""){}
    telefone(QString ddi,QString ddd,QString numero):ddi(ddi),ddd(ddd),numero(numero){}
    QString getTelefone()const;
    void setTelefone(QString ddi, QString ddd, QString numero);
    //refazer cod
    QString desmaterializar()const;
    void materializar(qs str);
};
}
#endif // TELEFONE_H
