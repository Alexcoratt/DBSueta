#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");
    model = new QSqlQueryModel;

    ui->tableView->setModel(model);

    bool connected = connect("192.168.0.105", "sueta", "rem_root", "remroot");
    if (connected){
        std::cout << "connected" << std::endl;
        updateModel();
    }
    else {
        std::cout << "error open database because" << std::endl;
        logOutput();
    }

    db->close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    delete model;
}

void MainWindow::logOutput() {
    std::cout << db->lastError().text().toStdString() << std::endl;
}

bool MainWindow::connect(QString hostname, QString dbName, QString userName, QString pwd) {
    db->setHostName(hostname);
    db->setDatabaseName(dbName);
    db->setUserName(userName);
    db->setPassword(pwd);

    return db->open();
}

void MainWindow::updateModel()
{
    QString mode(' ');
    if (ui->radioAll->isChecked())
        mode = ' ';
    else if (ui->radioEarlier->isChecked())
        mode = '<';
    else if (ui->radioLater->isChecked())
        mode = '>';
    else if (ui->radioMax->isChecked())
        mode = "max";
    else if (ui->radioMin->isChecked())
        mode = "min";

    QString temp("CALL get_people('%1', '%2');");
    QString qry = temp.arg(ui->filtDateEdit->date().toString("yyyy-MM-dd"), mode);
    QSqlQuery query;

    db->open();
    bool executed = query.exec(qry);
    db->close();

    if (executed)
        std::cout << "executed" << '\t' << query.executedQuery().toStdString() << std::endl;
    else {
        std::cout << "not executed" << std::endl <<
                     query.lastError().type() << '\t' << query.lastError().text().toStdString() << std::endl <<
                     db->lastError().type() << std::endl <<
                     model->lastError().type() << std::endl;
    }

    model->setQuery(query);
}

void MainWindow::addUser(QString login, QString name, QString bio, QDate birthdate, QString sex) {
    QString temp("CALL add_person('%1', '%2', '%3', '%4', '%5');");
    QString qry = temp.arg(login, name, bio, birthdate.toString("yyyy-MM-dd"), sex);

    std::cout << qry.toStdString() << std::endl;

    QSqlQuery query(*db);

    db->open();
    query.exec(qry);
    db->close();
}

void MainWindow::deleteUser(QString id) {
    QString temp("CALL delete_person('%1')");
    QString qry = temp.arg(id);
    QSqlQuery query(*db);

    db->open();
    query.exec(qry);
    db->close();
}

void MainWindow::on_addRecButton_clicked()
{
    QString login = ui->loginEdit->text();
    QString name = ui->nameEdit->text();
    QString bio = ui->bioEdit->toPlainText();
    QDate birthdate = ui->dateEdit->date();
    QString sex = ui->sexBox->currentText();
    addUser(login, name, bio, birthdate, sex);
    updateModel();
    logOutput();
}


void MainWindow::on_refreshButton_clicked()
{
    updateModel();
}


void MainWindow::on_delRecButton_clicked()
{
    deleteUser(ui->idBox->text());
    updateModel();
}

