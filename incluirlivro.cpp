#include "incluirlivro.h"
#include "ui_incluirlivro.h"
#include <QString>

IncluirLivro::IncluirLivro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
}

void IncluirLivro::clear() {
    ui->lineEditAutor->setText("");
    ui->lineEditPreco->setText("");
    ui->lineEditNome->setText("");
}

void IncluirLivro::on_IncluirLivro_accepted()
{
    QString nome = ui->lineEditNome->text();
    QString autor = ui->lineEditAutor->text();
    QString preco = ui->lineEditPreco->text();

    emit signIncluirLivro(nome,autor,preco);
}

