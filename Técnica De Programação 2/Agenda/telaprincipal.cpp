#include "telaprincipal.h"
#include "ui_telaprincipal.h"
#include <QPixmap>
#include <QFileDialog>
#include <cliente.h>
#include <iostream>
#include <id.h>
#include <categoria.h>

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
//    ui->tableWidgetCategoria->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}
void TelaPrincipal::limparTela()const
{
    ui->lineEditNomeCliente->clear();
    ui->lineEditCep->clear();
    ui->lineEditComplemento->clear();
    ui->lineEditLogradouro->clear();
    ui->lineEditDDD->clear();
    ui->lineEditDDI->clear();
    ui->lineEditTelefone->clear();
    ui->lineEditEmail->clear();
    ui->labelImagem->clear();
    ui->labelImagem->setText("   Imagem");
}

void TelaPrincipal::on_pushButtonIncluir_clicked()
{
    try {


       QString nome = ui->lineEditNomeCliente->text();
       QString logradouro = ui->lineEditLogradouro->text();
       QString complemento = ui->lineEditComplemento->text();
       QString cep = ui->lineEditCep->text();
       QString ddi = ui->lineEditDDI->text();
       QString ddd = ui->lineEditDDD->text();
       QString telefone = ui->lineEditTelefone->text();
       QString email = ui->lineEditEmail->text();
       QString cat = ui->comboBox->currentText();
       QString c = ui->lineEditIdcat->text();

       ava::Id id("id.txt");
       int ide = id.pegar();

       id.atualizar();
       if(cat == "Outro")
       {
           cat = QInputDialog::getText(this,"Outros","Digite um Novo Relacionamento");
           ui->comboBox->insertItem(4,cat);
       }

       ava::telefone tele(ddi,ddd,telefone);
       ava::endereco endereco(logradouro,complemento,cep);
       ava::cliente cliente(nome,endereco,tele,ArquivoEscolhido,email,cat,QString::number(ide));
       ava::clientePersistencia agenda("AgendaCliente.txt");

       agenda.incluir(cliente);
       limparTela();

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}

void TelaPrincipal::on_pushButtonADDimg_clicked()
{
    ArquivoEscolhido = QFileDialog::getOpenFileName(this,tr("Escolher Imagem"), "/home/alisson/Downloads", tr("Image Files (*.png *.jpeg *.bmp)"));
    QPixmap img(ArquivoEscolhido);
    ui->labelImagem->setPixmap(img.scaled(161,161,Qt::KeepAspectRatio));
}

void TelaPrincipal::on_pushButtonListagem_clicked()
{
    TelaListagem telaListar;
    telaListar.setModal(true);
    telaListar.exec();
}


void TelaPrincipal::on_pushButtonCAtt_clicked()
{
    Categoria cat;
    cat.setModal(true);
    cat.exec();
}
