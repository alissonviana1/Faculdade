#ifndef CLIENTEPERSISTENCIA_H
#define CLIENTEPERSISTENCIA_H
#include <cliente.h>
#include <crud.h>
#include <QString>
#include <fstream>
#include <telefone.h>

namespace ava{
typedef QString qs;
class clientePersistencia:public crud
{

private:
    qs nomeDoArquivoNoDisco;
public:
    clientePersistencia(qs nome);
    void incluir(cliente &obj) const;
    void tirar(QString id)const;
    void alterar(QString ide, int coluna, QString alt)const;
    void alterarTelefone(qs id, qs ddi, qs ddd, qs numero)const;
    std::list<cliente>* listagem()const;
};
}
#endif // CLIENTEPERSISTENCIA_H
