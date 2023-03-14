#include <iostream>
#include <string>
#include "get_order_items_command.hpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connector.hpp"
#include "add_person_command.hpp"
#include "update_people_model_command.hpp"
#include "delete_person_command.hpp"
#include "get_person_orders_command.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connector_ = new Connector();
    peopleModel_ = new Model();
    orderModel_ = new Model();
    orderedItemsModel_ = new Model();

    ui_->peopleTableView->setModel(peopleModel_->get());
    ui_->ordersTableView->setModel(orderModel_->get());
    ui_->orderContentsView->setModel(orderedItemsModel_->get());

    bool connected = connector_->connect("192.168.0.111", "sueta", "rem_root", "remroot");
    std::cout << (connected ? "connected" : "not connected") << std::endl;

    on_refreshButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui_;
    delete connector_;
    delete peopleModel_;
    delete orderModel_;
    delete orderedItemsModel_;
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

    int rowCount = peopleModel_->get()->rowCount();
    int const loginCol = 1;
    int const nameCol = 2;

    ui_->orderPeopleComboBox->clear();
    for (int i = 0; i < rowCount; ++i) {
        ui_->orderPeopleComboBox->addItem(peopleModel_->get()->index(i, loginCol).data().toString() + '\t' + peopleModel_->get()->index(i, nameCol).data().toString());
    }
}


void MainWindow::on_delRecButton_clicked()
{
    unsigned id = ui_->idBox->value();
    DeletePersonCommand del(id);
    std::string err = del.execute(peopleModel_, connector_).text().toStdString();
    std::cout << err << std::endl;
    on_refreshButton_clicked();
}


void MainWindow::on_orderPeopleComboBox_currentIndexChanged(int index)
{
    GetPersonOrdersCommand gpoc(peopleModel_->get()->index(index, 0).data().toUInt());
    std::string err = gpoc.execute(orderModel_, connector_).text().toStdString();
    std::cout << err << std::endl;
}


void MainWindow::on_ordersTableView_activated(const QModelIndex &index)
{
    GetOrderItemsCommand goic(index.data().toUInt());
    std::string err = goic.execute(orderedItemsModel_, connector_).text().toStdString();
    std::cout << err << std::endl;
}

