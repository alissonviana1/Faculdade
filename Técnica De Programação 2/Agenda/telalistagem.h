#ifndef TELALISTAGEM_H
#define TELALISTAGEM_H

#include <QMessageBox>
#include <list>
#include <QString>
#include <clientepersistencia.h>
#include <cliente.h>
#include <QDialog>
#include <QInputDialog>

namespace Ui {
class TelaListagem;
}

class TelaListagem : public QDialog
{
    Q_OBJECT

public:
    explicit TelaListagem(QWidget *parent = 0);
    ~TelaListagem();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonListasDados_clicked();

    void on_pushButton_clicked();

    void on_pushButtonAlterarDado_clicked();

    void on_pushButtonPorId_clicked();

private:
    Ui::TelaListagem *ui;
};

#endif // TELALISTAGEM_H
