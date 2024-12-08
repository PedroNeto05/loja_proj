#include "mainloja.h"
#include "ui_mainloja.h"
#include <QFileDialog>

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
    std::string filename = QFileDialog::getOpenFileName(
        nullptr,
        "Ler estoque",
        QString(),
        "Text Files (*.txt)"
        ).toStdString();
}

