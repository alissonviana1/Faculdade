#ifndef TELACATEGORIA_H
#define TELACATEGORIA_H

#include <QDialog>

namespace Ui {
class telacategoria;
}

class telacategoria : public QDialog
{
    Q_OBJECT

public:
    explicit telacategoria(QWidget *parent = 0);
    ~telacategoria();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::telacategoria *ui;
};

#endif // TELACATEGORIA_H
