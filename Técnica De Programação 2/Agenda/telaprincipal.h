#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include "telefone.h"
#include <QMainWindow>
#include <QMessageBox>
#include <cliente.h>
#include <endereco.h>
#include <clientepersistencia.h>
#include <telalistagem.h>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = nullptr);
    ~TelaPrincipal();

private slots:
    void limparTela()const;
    void on_pushButtonIncluir_clicked();

    void on_pushButtonADDimg_clicked();

    void on_pushButtonListagem_clicked();


    void on_pushButtonCAtt_clicked();

private:
    Ui::TelaPrincipal *ui;
    QString ArquivoEscolhido;
    int lin = 5;
};

#endif // TELAPRINCIPAL_H
