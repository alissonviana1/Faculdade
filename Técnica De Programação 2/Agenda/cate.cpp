#include "cate.h"
#include <iostream>
#include <bits/stdc++.h>
namespace ava {
cate::cate(QString nome)
{
    nomeDoArquivoNoDisco = nome;
}

void cate::incluir(CaCompleto &no) const
{
    std::ofstream arquivoCategoria;
    arquivoCategoria.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
    if(!arquivoCategoria.is_open())
    {
        throw qs("Arquivo de agenda nao foi aberto - Metodo incluir");
    }
    arquivoCategoria<<no.desmaterializar().toStdString()+"\n";
    arquivoCategoria.close();
}

std::list<CaCompleto>* cate::listagem()const
{
    try
    {
        std::ifstream arquivoCategoria;
        arquivoCategoria.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
        if(!arquivoCategoria.is_open())
        {
            throw qs("Arquivo de agenda nao foi aberto - Metodo listar");
        }

        std::list<CaCompleto> *lista = new std::list<CaCompleto>();
        std::string linha;
        getline(arquivoCategoria,linha);

        while(!arquivoCategoria.eof())
        {
            ava::CaCompleto cat;
            QString str = QString::fromStdString(linha);
            cat.materializar(str);
            lista->push_back(cat);
            getline(arquivoCategoria,linha);
        }
        arquivoCategoria.close();
        if(!lista->empty())
            return lista;
        else
        {
            throw QString("Lista Vazia");
        }
    }catch (QString &erro) {
        throw qs(erro);
//        QMessageBox::information(this,"ERRO", erro);
    }
}

void cate::tirar(QString id) const
{
    try {

        std::list<CaCompleto> *lista = new std::list<CaCompleto>();
        lista = this->listagem();
        std::ofstream arquivoCategoria;
        ava::cate arquivoCa("Categoria.txt");
        arquivoCategoria.open("Categoria.txt");
        if(!arquivoCategoria.is_open())
        {
            throw qs("Arquivo de agenda nao foi aberto - Metodo tirar");
        }
        arquivoCategoria.close();
        while(!lista->empty())
        {
            ava::CaCompleto obj = lista->front();
            lista->pop_front();
            if(obj.getId() != id)
            {
                arquivoCa.incluir(obj);
            }
        }

    } catch (QString &erro) {
        throw(erro);
     }

}

}
