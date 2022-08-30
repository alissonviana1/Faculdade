#include "telalistagem.h"
#include "ui_telalistagem.h"
#include <QMessageBox>
#include <list>
#include <QString>
#include <clientepersistencia.h>
#include <cliente.h>
#include <QDialog>
#include <QPixmap>
#include <QInputDialog>
#include <iostream>
#include <QPixmap>
#include <QFileDialog>

TelaListagem::TelaListagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaListagem)
{
    ui->setupUi(this);
    ui->tableWidgetListagem->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

TelaListagem::~TelaListagem()
{
    delete ui;
}

void TelaListagem::on_pushButtonVoltar_clicked()
{
    this->close();
}

void TelaListagem::on_pushButtonListasDados_clicked()
{
    try {

        ava::clientePersistencia agendaClientes("AgendaCliente.txt");
        std::list<ava::cliente> * lista = 0;
        lista = agendaClientes.listagem();
        ui->tableWidgetListagem->setRowCount(0);


        while(!lista->empty())
        {
            ava::cliente obj = lista->front();
            lista->pop_front();

            QTableWidgetItem *itemFoto = new QTableWidgetItem();
            QTableWidgetItem *itemNome = new QTableWidgetItem(obj.getNomeCompleto());
            QTableWidgetItem *itemLogradouro = new QTableWidgetItem(obj.getEnderecoResidencial().getLogradouro());
            QTableWidgetItem *itemComplemento = new QTableWidgetItem(obj.getEnderecoResidencial().getComplemento());
            QTableWidgetItem *itemCEP = new QTableWidgetItem(obj.getEnderecoResidencial().getCep());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(obj.getTelefone().getTelefone());
            QTableWidgetItem *itemEmail = new QTableWidgetItem(obj.getEmail());
            QTableWidgetItem *itemCat = new QTableWidgetItem(obj.getCategoria());
            QTableWidgetItem *itemID = new QTableWidgetItem(obj.getId());
//            QTableWidgetItem *itemC = new QTableWidgetItem(obj.getCat());

            itemFoto->setIcon(QPixmap(obj.getFoto()));

            int linha = ui->tableWidgetListagem->rowCount();

            ui->tableWidgetListagem->insertRow(linha);
            ui->tableWidgetListagem->setItem(linha, 0, itemFoto);
            ui->tableWidgetListagem->setItem(linha, 1,itemID);
            ui->tableWidgetListagem->setItem(linha, 2, itemNome);
            ui->tableWidgetListagem->setItem(linha, 3, itemLogradouro);
            ui->tableWidgetListagem->setItem(linha, 4, itemComplemento);
            ui->tableWidgetListagem->setItem(linha, 5, itemCEP);
            ui->tableWidgetListagem->setItem(linha, 6, itemTelefone);
            ui->tableWidgetListagem->setItem(linha, 7, itemEmail);
            ui->tableWidgetListagem->setItem(linha, 8, itemCat);
//            ui->tableWidgetListagem->setItem(linha, 9, itemC);

            ui->tableWidgetListagem->sortItems(2);
            ui->tableWidgetListagem->resizeColumnsToContents();

        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void TelaListagem::on_pushButton_clicked()
{
    try {
        int linha = -1;
        linha = ui->tableWidgetListagem->currentRow();
        if(ui->tableWidgetListagem->rowCount() == 0)
            throw QString("Nao contem contatos");
        if(linha == -1)
            throw QString("Nenhum contato selecionado");
        ava::clientePersistencia agendaCliente("AgendaCliente.txt");

        int elemento = ui->tableWidgetListagem->currentRow();

        QString id = ui->tableWidgetListagem->item(elemento, 1)->text();

        ui->tableWidgetListagem->removeRow(elemento);
        agendaCliente.tirar(id);

    }  catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void TelaListagem::on_pushButtonAlterarDado_clicked()
{
    try {

        ava::clientePersistencia agendaCliente("AgendaCliente.txt");

        int linha = -1, coluna = -1;
        linha = ui->tableWidgetListagem->currentRow();
        coluna = ui->tableWidgetListagem->currentColumn();

        if(linha == -1 && coluna == -1) throw QString("Selecione onde deseja alterar");

        QString alte;
        if(coluna == 0)
        {
           QString foto = QFileDialog::getOpenFileName(this,tr("Escolher Imagem"), "/home/alisson/Downloads", tr("Image Files (*.png *.jpeg *.bmp)"));
           QPixmap img(foto);
           QTableWidgetItem * ft = new QTableWidgetItem(foto);
           ft->setIcon(QPixmap(foto));
           ui->tableWidgetListagem->setItem(linha,coluna, ft);
           QString ide = ui->tableWidgetListagem->item(linha,1)->text();
           agendaCliente.alterar(ide,coluna,foto);
        }
        else
        {
            if(coluna == 6)
            {
                int n = 3;
                QString ddi,ddd,numero;
                while(n--)
                {
                    if(n == 2)
                    {
                        ddi = QInputDialog::getText(this,"DDI","Digite o DDI");
                    }
                    if(n == 1)
                    {
                        ddd = QInputDialog::getText(this,"DDD","Digite o DDD");
                    }
                    if(n == 0)
                    {
                        numero = QInputDialog::getText(this,"Numero","Digite o Numero");
                    }
                }
                QString ide = ui->tableWidgetListagem->item(linha,1)->text();
                agendaCliente.alterarTelefone(ide,ddi,ddd,numero);
                QString crt = ddi + "(" + ddd + ")" + numero;
                QTableWidgetItem * t = new QTableWidgetItem(crt);
                ui->tableWidgetListagem->setItem(linha,coluna,t);

            }
            else
            {
                if(coluna == 1)
                {
                    QMessageBox::information(this,"ERRO","Impossivel mudar ID!");
                }
                else
                {
                    alte = QInputDialog::getText(this,"Alterar", "Alterar linha " + QString::number(linha+1) + ", coluna "+ QString::number(coluna+1));
                    QTableWidgetItem* alt = new QTableWidgetItem(alte);
                    ui->tableWidgetListagem->setItem(linha,coluna, alt);
                    QString ide = ui->tableWidgetListagem->item(linha,1)->text();
                    agendaCliente.alterar(ide,coluna,alte);
                }
            }
        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void TelaListagem::on_pushButtonPorId_clicked()
{
    try {

        ava::clientePersistencia agendaClientes("AgendaCliente.txt");
        std::list<ava::cliente> * lista = 0;
        lista = agendaClientes.listagem();
        ui->tableWidgetListagem->setRowCount(0);


        while(!lista->empty())
        {
            ava::cliente obj = lista->front();
            lista->pop_front();

            QTableWidgetItem *itemFoto = new QTableWidgetItem();
            QTableWidgetItem *itemNome = new QTableWidgetItem(obj.getNomeCompleto());
            QTableWidgetItem *itemLogradouro = new QTableWidgetItem(obj.getEnderecoResidencial().getLogradouro());
            QTableWidgetItem *itemComplemento = new QTableWidgetItem(obj.getEnderecoResidencial().getComplemento());
            QTableWidgetItem *itemCEP = new QTableWidgetItem(obj.getEnderecoResidencial().getCep());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(obj.getTelefone().getTelefone());
            QTableWidgetItem *itemEmail = new QTableWidgetItem(obj.getEmail());
            QTableWidgetItem *itemCat = new QTableWidgetItem(obj.getCategoria());
            QTableWidgetItem *itemID = new QTableWidgetItem(obj.getId());
//            QTableWidgetItem *itemC = new QTableWidgetItem(obj.getCat());

            itemFoto->setIcon(QPixmap(obj.getFoto()));

            int linha = ui->tableWidgetListagem->rowCount();

            ui->tableWidgetListagem->insertRow(linha);
            ui->tableWidgetListagem->setItem(linha, 0, itemFoto);
            ui->tableWidgetListagem->setItem(linha, 1,itemID);
            ui->tableWidgetListagem->setItem(linha, 2, itemNome);
            ui->tableWidgetListagem->setItem(linha, 3, itemLogradouro);
            ui->tableWidgetListagem->setItem(linha, 4, itemComplemento);
            ui->tableWidgetListagem->setItem(linha, 5, itemCEP);
            ui->tableWidgetListagem->setItem(linha, 6, itemTelefone);
            ui->tableWidgetListagem->setItem(linha, 7, itemEmail);
            ui->tableWidgetListagem->setItem(linha, 8, itemCat);
//            ui->tableWidgetListagem->setItem(linha, 9, itemC);

            ui->tableWidgetListagem->sortItems(1);
            ui->tableWidgetListagem->resizeColumnsToContents();

        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}
