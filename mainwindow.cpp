#include <iostream>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connector.hpp"
#include "add_person_command.hpp"
#include "update_people_model_command.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connector_ = new Connector();
    peopleModel_ = new PeopleModel();

    ui_->peopleTableView->setModel(peopleModel_->get());

    bool connected = connector_->connect("192.168.0.111", "sueta", "rem_root", "remroot");
    std::cout << (connected ? "connected" : "not connected") << std::endl;

    on_refreshButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui_;
    delete connector_;
    delete peopleModel_;
}


void MainWindow::on_addRecButton_clicked()
{
    QString login = ui_->loginEdit->text();
    QString name = ui_->nameEdit->text();
    QString bio = ui_->bioEdit->toPlainText();
    QDate birthdate = ui_->dateEdit->date();
    QString sex = ui_->sexBox->currentText();

    AddPersonCommand addUsr(login, name, bio, birthdate, sex);
    std::string err = addUsr.execute(peopleModel_, connector_).text().toStdString();
    std::cout << err << std::endl;
    on_refreshButton_clicked();
}


void MainWindow::on_refreshButton_clicked()
{
    QString mode(' ');
    if (ui_->radioAll->isChecked())
        mode = ' ';
    else if (ui_->radioEarlier->isChecked())
        mode = '<';
    else if (ui_->radioLater->isChecked())
        mode = '>';
    else if (ui_->radioMax->isChecked())
        mode = "max";
    else if (ui_->radioMin->isChecked())
        mode = "min";

    UpdatePeopleModelCommand upd(ui_->filtDateEdit->date(), mode);
    std::string err = upd.execute(peopleModel_, connector_).text().toStdString();
    std::cout << err << std::endl;
}


void MainWindow::on_delRecButton_clicked()
{

}

