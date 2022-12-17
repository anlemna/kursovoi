#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    baza = QSqlDatabase::addDatabase("QSQLITE");
    baza.setDatabaseName("./baza.db");
    if(baza.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }

    query = new QSqlQuery(baza);
    query->exec("CREATE TABLE Teeth(Number INT, Date DATE);");

    model = new QSqlTableModel(this, baza);
    model->setTable("Teeth");
    model->select();

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int i=0; i<20; i++)
    {
       model->insertRow(model->rowCount());
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row=index.row();
}
