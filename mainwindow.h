#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QDebug>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase baza;
    QSqlQuery *query;
    QSqlTableModel *model;

    int row;
};

#endif // MAINWINDOW_H
