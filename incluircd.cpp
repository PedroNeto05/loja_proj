#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear() {

}

void IncluirCD::on_IncluirCD_accepted()
{
    QString nome = ui->lineEditNome->text();
    QString preco = ui->lineEditPreco->text();
    QString numFaixas = ui->lineEditNumFaixas->text();

    emit signIncluirCD(nome,preco,numFaixas);
}

