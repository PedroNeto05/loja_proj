#include "mainloja.h"
#include "ui_mainloja.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QLabel>
#include <QString>


MainLoja::MainLoja(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLoja),
    inclLivro(new IncluirLivro(this)),
    inclCD(new IncluirCD(this)),
    inclDVD(new IncluirDVD(this)),
    total_itens(new QLabel(this))
{
    ui->setupUi(this);

    statusBar()->insertWidget(0,new QLabel("Total de itens: "));
    statusBar()->insertWidget(1,total_itens);

    connect(inclLivro,&IncluirLivro::signIncluirLivro,this,&MainLoja::slotIncluirLivro);
    connect(inclCD,&IncluirCD::signIncluirCD,this,&MainLoja::slotIncluirCD);
    connect(inclDVD,&IncluirDVD::signIncluirDVD,this,&MainLoja::slotIncluirDVD);

    ui->labelLivros->setStyleSheet("background-color:lightgray");
    ui->labelCds->setStyleSheet("background-color:lightgray");
    ui->labelDvds->setStyleSheet("background-color:lightgray");

    ui->tableLivros->setStyleSheet("QHeaderView::section { background-color:lightgray }");
    ui->tableCds->setStyleSheet("QHeaderView::section { background-color:lightgray }");
    ui->tableDvds->setStyleSheet("QHeaderView::section { background-color:lightgray }");

    ui->tableLivros->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableLivros->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableLivros->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    ui->tableCds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableCds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableCds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    ui->tableDvds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableDvds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableDvds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    total_itens->setNum(0);
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
        this,
        "Ler estoque",
        QString(),
        "Text Files (*.txt)"
        );

    if (filename.isEmpty()) {
        return;
    }

    if (!X.ler(filename.toStdString())) {
        QMessageBox::critical(this, "Erro", "Não foi possivel ler o arquivo");
        return;
    }
}


void MainLoja::on_actionSalvar_triggered()
{
    QString filename = QFileDialog::getSaveFileName(
        this,
        "Salvar estoque",
        QString(),
        "Text Files (*.txt)"
        );
    if (filename.isEmpty()) {
        return;
    }
    if (!X.salvar(filename.toStdString())) {
        QMessageBox::critical(this, "Erro", "Não foi possivel salvar o arquivo");
        return;
    }
}


void MainLoja::on_actionSair_triggered()
{
    QCoreApplication::quit();
}


void MainLoja::on_actionIncluir_Livro_triggered()
{
    inclLivro->clear();
    inclLivro->show();

}


void MainLoja::on_actionIncluir_CD_triggered()
{
    inclCD->clear();
    inclCD->show();
}


void MainLoja::on_actionIncluir_DVD_triggered()
{
    inclDVD->clear();
    inclDVD->show();
}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor) {

    std::string nomeStr = nome.toStdString();
    double precoDouble = preco.toDouble();
    std::string autorStr = autor.toStdString();

    if (nomeStr.empty() || precoDouble <= 0.0 || autorStr.empty()) {
        QMessageBox::critical(this, "Livro inválido", QString("Não foi possível incluir o Livro:\nNome=%1\nPreço=%2\nAutor=%3")
                                                          .arg(nome.isEmpty() ? "<vazio>" : nome)
                                                          .arg(preco.isEmpty() ? "<vazio>" : preco)
                                                          .arg(autor.isEmpty() ? "<vazio>" : autor));
        return;
    }


    X.incluirLivro(Livro (nomeStr, precoDouble, autorStr));
    atualizarTableLivros();

}

void MainLoja::slotIncluirCD(QString nome, QString preco, QString numfaixas) {
    std::string nomeStr = nome.toStdString();
    double precoDouble = preco.toDouble();
    int numFaixasInt = numfaixas.toInt();

    if (nomeStr.empty() || precoDouble <= 0.0 || numFaixasInt <= 0) {
        QMessageBox::critical(this, "CD inválido", QString("Não foi possível incluir o CD:\nNome=%1\nPreço=%2\nNúmero de faixas=%3")
                                                       .arg(nome.isEmpty() ? "<vazio>" : nome)
                                                       .arg(preco.isEmpty() ? "<vazio>" : preco)
                                                       .arg(numfaixas.isEmpty() ? "<vazio>" : numfaixas));
        return;
    }

    X.incluirCD(CD(nomeStr, precoDouble, numFaixasInt));
}

void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao) {
    std::string nomeStr = nome.toStdString();
    double precoDouble = preco.toDouble();
    double duracaoDouble = duracao.toDouble();

    if (nomeStr.empty() || precoDouble <= 0.0 || duracaoDouble <= 0.0) {
        QMessageBox::critical(this, "DVD inválido", QString("Não foi possível incluir o DVD:\nNome=%1\nPreço=%2\nDuração=%3")
                                                        .arg(nome.isEmpty() ? "<vazio>" : nome)
                                                        .arg(preco.isEmpty() ? "<vazio>" : preco)
                                                        .arg(duracao.isEmpty() ? "<vazio>" : duracao));
        return;
    }

    X.incluirDVD(DVD(nomeStr, precoDouble, duracaoDouble));
}

void MainLoja::atualizarTableLivros() {
    int numRows = X.getNumLivro();

    ui->tableLivros->clearContents();

    ui->tableLivros->setRowCount(numRows);


    for (int i = 0; i < numRows; ++i) {
        Livro L = X.getLivro(i);  // Obtém o i-ésimo livro de X

        // Criando o QLabel para o nome do livro
        QLabel *nomeLabel = new QLabel(L.getNome().c_str());
        nomeLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tableLivros->setCellWidget(i, 0, nomeLabel); // Coluna 0 para nome

        // Criando o QLabel para o preço, formatando para 2 casas decimais
        QString precoFormatado = QString::number(L.getPreco(), 'f', 2);
        QLabel *precoLabel = new QLabel(precoFormatado);
        precoLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tableLivros->setCellWidget(i, 1, precoLabel); // Coluna 2 para preço


        // Criando o QLabel para o autor
        QLabel *autorLabel = new QLabel(L.getAutor().c_str());
        autorLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tableLivros->setCellWidget(i, 2, autorLabel); // Coluna 1 para autor


    }
}

void MainLoja::atualizarTableCds() {

}

void MainLoja::atualizarTableDvds() {

}
