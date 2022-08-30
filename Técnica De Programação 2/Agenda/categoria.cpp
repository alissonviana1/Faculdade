#include "categoria.h"
#include "ui_categoria.h"
#include <QInputDialog>
#include <QMessageBox>
#include <cate.h>
#include <list>
#include <QString>
#include <cacompleto.h>
#include <QDialog>
#include <QPixmap>
#include <QInputDialog>
#include <iostream>
#include <QPixmap>
#include <QFileDialog>
#include <id.h>

Categoria::Categoria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categoria)
{
    ui->setupUi(this);
}

Categoria::~Categoria()
{
    delete ui;
}


void Categoria::on_pushButtonVoltarCa_clicked()
{
    this->close();
}

void Categoria::on_pushButtonIncluirCa_clicked()
{
    try {

        QString cate = QInputDialog::getText(this,"Leitura","Informe a categoria desejada.");
        ava::cate categoria("Categoria.txt");
        ava::Id id("id.txt");
        int ide = id.pegar();

        id.atualizar();


        ava::CaCompleto obj(cate,QString::number(ide));
        categoria.incluir(obj);


    } catch (QString &erro) {
        throw QString(erro);
    }
}

void Categoria::on_pushButtonApagarCa_clicked()
{
    try {
        int linha = -1;
        linha = ui->tableWidgetCate->currentRow();
        if(ui->tableWidgetCate->rowCount() == 0)
            throw QString("Nao contem contatos");
        if(linha == -1)
            throw QString("Nenhum contato selecionado");
        ava::cate categoria("Categoria.txt");

        int elemento = ui->tableWidgetCate->currentRow();

        QString id = ui->tableWidgetCate->item(elemento, 0)->text();

        ui->tableWidgetCate->removeRow(elemento);
        categoria.tirar(id);

    }  catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void Categoria::on_pushButtonListarCa_clicked()
{
    try {

        ava::cate categoria("Categoria.txt");
        std::list<ava::CaCompleto> * lista = 0;
        lista = categoria.listagem();
        ui->tableWidgetCate->setRowCount(0);

        while(!lista->empty())
        {
            ava::CaCompleto obj = lista->front();
            lista->pop_front();

            QTableWidgetItem *itemId = new QTableWidgetItem(obj.getId());
            QTableWidgetItem *itemNome = new QTableWidgetItem(obj.getNome());

            int linha = ui->tableWidgetCate->rowCount();

            ui->tableWidgetCate->insertRow(linha);
            ui->tableWidgetCate->setItem(linha, 1, itemNome);
            ui->tableWidgetCate->setItem(linha, 0,itemId);
            ui->tableWidgetCate->resizeColumnsToContents();

        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}
