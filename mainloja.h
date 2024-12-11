#ifndef MAINLOJA_H
#define MAINLOJA_H

#include <QMainWindow>
#include "loja.h"
#include "incluirlivro.h"
#include "incluircd.h"
#include "incluirdvd.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainLoja;
}
QT_END_NAMESPACE

class MainLoja : public QMainWindow
{
    Q_OBJECT

public:
    MainLoja(QWidget *parent = nullptr);
    ~MainLoja();

public slots:
    void slotIncluirLivro(QString nome, QString preco, QString autor);
    void slotIncluirCD(QString nome, QString preco, QString numfaixas);
    void slotIncluirDVD(QString nome, QString preco, QString duracao);

private slots:
    void on_tableLivros_cellDoubleClicked(int row, int column);

    void on_tableCds_cellDoubleClicked(int row, int column);

    void on_tableDvds_cellDoubleClicked(int row, int column);

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionIncluir_Livro_triggered();

    void on_actionIncluir_CD_triggered();

    void on_actionIncluir_DVD_triggered();



private:
    Ui::MainLoja *ui;
    Loja X;
    IncluirLivro* inclLivro;
    IncluirCD* inclCD;
    IncluirDVD* inclDVD;
    QLabel* total_itens;

    void atualizarTableLivros();
    void atualizarTableCds();
    void atualizarTableDvds();
    void atualizarTotalItens();


};
#endif // MAINLOJA_H
