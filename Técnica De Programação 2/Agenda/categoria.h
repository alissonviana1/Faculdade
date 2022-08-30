#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <QDialog>

namespace Ui {
class Categoria;
}

class Categoria : public QDialog
{
    Q_OBJECT

public:
    explicit Categoria(QWidget *parent = 0);
    ~Categoria();
    void adicionar(QString nome);
    void remover(QString nome);

private slots:
    void on_pushButtonVoltarCa_clicked();

    void on_pushButtonIncluirCa_clicked();

    void on_pushButtonApagarCa_clicked();

    void on_pushButtonListarCa_clicked();

private:
    Ui::Categoria *ui;
};

#endif // CATEGORIA_H
