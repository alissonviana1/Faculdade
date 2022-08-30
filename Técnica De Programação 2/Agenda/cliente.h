#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>
#include <endereco.h>
#include <list>
#include <itransformardados.h>
#include <telefone.h>

namespace ava{
typedef QString qs;
class cliente: public ITransformarDados
{
private:
    qs nomeCompleto;
    endereco enderecoResidencial;
    telefone tele;
    QString foto;
    qs email;
    qs categotia;
    qs id;


public:
    cliente();
    cliente(qs nome, endereco endereco,telefone tele,QString foto,qs email, qs categotia,qs id);
    qs getNomeCompleto()const{return nomeCompleto;}
    void setNomeCompleto(qs nome){this->nomeCompleto = nome;}
    endereco getEnderecoResidencial()const{return enderecoResidencial;}
    void setEnderecoResidecial(endereco objEnde){this->enderecoResidencial = objEnde;}
    telefone getTelefone()const{return tele;}
    void setTelefone(telefone tele){this->tele = tele;}
    QString getFoto()const{return foto;}
    void setFoto(QString foto){this->foto = foto;}
    qs getEmail()const{return email;}
    void setEmail(qs email){this->email = email;}
    qs getCategoria()const{return categotia;}
    void setCategoria(qs cat){this->categotia = cat;}
    qs getId()const{return id;}
    void setId(qs id){this->id = id;}
//    qs getCat()const{return cat;}
//    void setCat(qs cat){this->cat = cat;}

    //reescrever
    qs desmaterializar()const;
    void materializar(qs str);
};
}
#endif // CLIENTE_H
