#include "mainloja.h"
#include "ui_mainloja.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

MainLoja::MainLoja(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLoja)
{
    ui->setupUi(this);
}

MainLoja::~MainLoja()
{
    delete ui;
}

void MainLoja::on_tableLivros_cellDoubleClicked(int row, int column)
{

}


void MainLoja::on_tableCds_cellDoubleClicked(int row, int column)
{

}


void MainLoja::on_tableDvds_cellDoubleClicked(int row, int column)
{

}


void MainLoja::on_actionLer_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        nullptr,
        "Ler estoque",
        QString(),
        "Text Files (*.txt)"
        );

    if (filename.isEmpty()) {
        return;
    }

    if (!X.ler(filename.toStdString())) {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }
}


void MainLoja::on_actionSalvar_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
        nullptr,
        "Salvar estoque",
        QString(),
        "Text Files (*.txt)"
        );
    if (filename.isEmpty()) {
        return;
    }
    if (!X.salvar(filename.toStdString())) {
        QMessageBox::critical(this, "Error", "Could not save file");
        return;
    }
}


void MainLoja::on_actionSair_triggered()
{
    QCoreApplication::quit();
}


void MainLoja::on_actionIncluir_Livro_triggered()
{

}


void MainLoja::on_actionIncluir_CD_triggered()
{

}


void MainLoja::on_actionIncluir_DVD_triggered()
{

}

