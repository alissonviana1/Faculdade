#include "telacategoria.h"
#include "ui_telacategoria.h"

telacategoria::telacategoria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telacategoria)
{
    ui->setupUi(this);
}

telacategoria::~telacategoria()
{
    delete ui;
}

void telacategoria::on_pushButton_2_clicked()
{

}
