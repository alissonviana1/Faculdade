#ifndef ID_H
#define ID_H
#include <bits/stdc++.h>
#include <QString>

namespace ava{
typedef QString qs;
class Id
{
private:
    qs nomeDoArquivoNoDisco;
public:
    Id(qs nome);
    int pegar();
    int atualizar();
    void incluir(int id);
};
}
#endif // ID_H
