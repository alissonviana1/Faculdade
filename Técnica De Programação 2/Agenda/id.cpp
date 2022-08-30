#include "id.h"
#include <iostream>
#include <QString>
#include <string>
#include <bits/stdc++.h>

namespace ava {

Id::Id(qs nome)
{
    nomeDoArquivoNoDisco = nome;
}

void Id::incluir(int id)
{
    std::ofstream arquivoID;
    arquivoID.open("id.txt");
    if(!arquivoID.is_open())
    {
        throw qs("Arquivo de agenda nao foi aberto - Metodo incluir");
    }
    arquivoID<<QString::number(id).toStdString();
    arquivoID.close();
}

int Id::pegar()
{
    std::ifstream arquivoID;
    arquivoID.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
    if(!arquivoID.is_open())
    {
        throw qs("Arquivo de agenda nao foi aberto - Metodo atualizar");
    }

    std::string linha;
    getline(arquivoID,linha);
    QString str = QString::fromStdString(linha);
    arquivoID.close();
    return str.toInt();
}

int Id::atualizar()
{
    int linha = this->pegar();
    linha++;

    std::ofstream arquivo;
    ava::Id arquivoID("id.txt");
    arquivo.open("id.txt");
    if(!arquivo.is_open())
    {
        throw qs("Arquivo de agenda nao foi aberto - Metodo tirar");
    }

    arquivoID.incluir(linha);
}


}
