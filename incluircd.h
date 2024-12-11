#ifndef INCLUIRCD_H
#define INCLUIRCD_H

#include <QDialog>

namespace Ui {
class IncluirCD;
}

class IncluirCD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirCD(QWidget *parent = nullptr);
    ~IncluirCD();
    void clear();

private:
    Ui::IncluirCD *ui;

signals:
    void signIncluirCD(QString nome, QString preco, QString numfaixas);

private slots:
    void on_IncluirCD_accepted();
};

#endif // INCLUIRCD_H
