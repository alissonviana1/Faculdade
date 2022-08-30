#include "cliente.h"

namespace ava{
cliente::cliente():
    nomeCompleto(""),
    enderecoResidencial(),
    tele(),
    foto(""),
    email(""),
    categotia(""),
    id("")
//    cat("")

{
}

cliente::cliente(qs nome, endereco endereco, telefone tele,QString foto, qs email, qs cat,qs id)
{
    this->nomeCompleto = nome;
    this->enderecoResidencial = endereco;
    this->tele = tele;
    this->foto = foto;
    this->email = email;
    this->categotia = cat;
    this->id = id;
//    this->cat = cate;
}

qs cliente::desmaterializar()const
{
   return (nomeCompleto + ";" + enderecoResidencial.desmaterializar() + ";" + tele.desmaterializar() + ";" + foto + ";" + email + ";" + categotia + ";" + id);
}

void cliente::materializar(qs str)
{
    QStringList dados = str.split(";");
    nomeCompleto = dados[0];
    enderecoResidencial.setLogradouro(dados[1]);
    enderecoResidencial.setComplemento(dados[2]);
    enderecoResidencial.setCep(dados[3]);
    tele.setTelefone(dados[4],dados[5],dados[6]);
    //foto
    foto = dados[7];
    email = dados[8];
    categotia = dados[9];
    id = dados[10];
//    cat = dados[11];

}

}
