#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void logOutput();
    bool connect(QString, QString, QString, QString);
    void updateModel();
    void addUser(QString, QString, QString, QDate, QString);
    void deleteUser(QString);

private slots:
    void on_addRecButton_clicked();

    void on_refreshButton_clicked();

    void on_delRecButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase * db;
    QSqlQueryModel * model;
};
#endif // MAINWINDOW_H
