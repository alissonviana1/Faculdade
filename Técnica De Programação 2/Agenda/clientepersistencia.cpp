#include "clientepersistencia.h"
#include <QString>
#include <telefone.h>
#include <QMessageBox>
#include <iostream>

namespace ava{

clientePersistencia::clientePersistencia(qs nome)
{
    nomeDoArquivoNoDisco = nome;
}

void clientePersistencia::incluir(cliente &obj) const
{
    std::ofstream arquivoAgenda;
    arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
    if(!arquivoAgenda.is_open())
    {
        throw qs("Arquivo de agenda nao foi aberto - Metodo incluir");
    }
    arquivoAgenda<<obj.desmaterializar().toStdString()+"\n";
    arquivoAgenda.close();
}

std::list<cliente>* clientePersistencia::listagem()const
{
    try
    {
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out|std::ios::app);
        if(!arquivoAgenda.is_open())
        {
            throw qs("Arquivo de agenda nao foi aberto - Metodo listar");
        }

        std::list<cliente> *lista = new std::list<cliente>();
        std::string linha;
        getline(arquivoAgenda,linha);

        while(!arquivoAgenda.eof())
        {
            ava::cliente objeto;
            QString str = QString::fromStdString(linha);
            objeto.materializar(str);
            lista->push_back(objeto);
            getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        if(!lista->empty())
            return lista;
        else
        {
            throw qs("Lista Vazia");
        }
    }catch (QString &erro) {
        throw qs(erro);
//        QMessageBox::information(this,"ERRO", erro);
    }
}

void clientePersistencia::tirar(QString id) const
{
    try {
        std::list<cliente> *lista = new std::list<cliente>();
        lista = this->listagem();
        std::ofstream arquivoAgenda;
        ava::clientePersistencia arquivoCliente("AgendaCliente.txt");
        arquivoAgenda.open("AgendaCliente.txt");
        if(!arquivoAgenda.is_open())
        {
            throw qs("Arquivo de agenda nao foi aberto - Metodo tirar");
        }
        arquivoAgenda.close();
        while(!lista->empty())
        {
            ava::cliente obj = lista->front();
            lista->pop_front();
            if(obj.getId() != id)
                arquivoCliente.incluir(obj);
        }

    } catch (QString &erro) {
        throw(erro);
     }

}
 void clientePersistencia::alterarTelefone(qs id, qs ddi, qs ddd, qs numero)const
 {
     try {

         std::list<cliente> *lista = new std::list<cliente>();
         lista = this->listagem();
         std::ofstream arquivoAgenda;
         ava::clientePersistencia arquivoCliente("AgendaCliente.txt");
         arquivoAgenda.open("AgendaCliente.txt");
         if(!arquivoAgenda.is_open())
         {
             throw qs("Arquivo de agenda nao foi aberto - Metodo alterar");
         }
         arquivoAgenda.close();

         ava::telefone tele;
         tele.setTelefone(ddi,ddd,numero);

         while(!lista->empty())
         {
             ava::cliente obj = lista->front();
             lista->pop_front();
             if(obj.getId() != id)
             {
                 arquivoCliente.incluir(obj);
             }
             else
             {
                 obj.setTelefone(tele);
                 arquivoCliente.incluir(obj);
             }
        }

     } catch (QString &erro) {
         throw(erro);
      }
 }

void clientePersistencia::alterar(QString ide, int coluna, QString alt) const
{
    try {

        std::list<cliente> *lista = new std::list<cliente>();
        lista = this->listagem();
        std::ofstream arquivoAgenda;
        ava::clientePersistencia arquivoCliente("AgendaCliente.txt");
        arquivoAgenda.open("AgendaCliente.txt");
        if(!arquivoAgenda.is_open())
        {
            throw qs("Arquivo de agenda nao foi aberto - Metodo alterar");
        }
        arquivoAgenda.close();
        while(!lista->empty())
        {
            ava::cliente obj = lista->front();
            ava::endereco end;

            lista->pop_front();

            if (coluna == 0) {
                if(obj.getId() != ide)
                {
                    arquivoCliente.incluir(obj);
                }
                else
                {
                    obj.setFoto(alt);
                    arquivoCliente.incluir(obj);
                }
            } else {
                if (coluna == 1) {
                    if(obj.getId() != ide)
                    {
                        arquivoCliente.incluir(obj);
                    }
                    else
                    {
                        obj.setId(alt);
                        arquivoCliente.incluir(obj);
                    }

                } else {
                    if (coluna == 2) {
                        if(obj.getId() != ide)
                        {
                            arquivoCliente.incluir(obj);
                        }
                        else
                        {
                            obj.setNomeCompleto(alt);
                            arquivoCliente.incluir(obj);
                        }

                    } else {
                        if (coluna == 3) {
                            if(obj.getId() != ide)
                            {
                                arquivoCliente.incluir(obj);
                            }
                            else
                            {
                                ava::endereco end = obj.getEnderecoResidencial();
                                end.setLogradouro(alt);
                                obj.setEnderecoResidecial(end);
                                arquivoCliente.incluir(obj);
                            }

                        } else {
                            if (coluna == 4) {
                                if(obj.getId() != ide)
                                {
                                    arquivoCliente.incluir(obj);
                                }
                                else
                                {

                                    ava::endereco end = obj.getEnderecoResidencial();
                                    end.setComplemento(alt);
                                    obj.setEnderecoResidecial(end);
                                    arquivoCliente.incluir(obj);
                                }

                            } else {
                                if (coluna == 5) {
                                    if(obj.getId() != ide)
                                    {
                                        arquivoCliente.incluir(obj);
                                    }
                                    else
                                    {
                                        ava::endereco end = obj.getEnderecoResidencial();
                                        end.setCep(alt);
                                        obj.setEnderecoResidecial(end);
                                        arquivoCliente.incluir(obj);
                                    }

                                } else {
                                    if(coluna == 6){
                                        if(obj.getId() != ide)
                                        {
                                            arquivoCliente.incluir(obj);
                                        }
                                        else
                                        {
                                            arquivoCliente.incluir(obj);
                                        }

                                    } else {
                                        if (coluna == 7) {
                                            if(obj.getId() != ide)
                                            {
                                                arquivoCliente.incluir(obj);
                                            }
                                            else
                                            {
                                                obj.setEmail(alt);
                                                arquivoCliente.incluir(obj);
                                            }

                                        } else {
                                            if (coluna == 8) {
                                                if(obj.getId() != ide)
                                                {
                                                    arquivoCliente.incluir(obj);
                                                }
                                                else
                                                {
                                                    obj.setCategoria(alt);
                                                    arquivoCliente.incluir(obj);
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    } catch (QString &erro) {
        throw(erro);
     }
}


}
