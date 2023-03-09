#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connector.hpp"
#include "people_model.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecButton_clicked();

    void on_refreshButton_clicked();

    void on_delRecButton_clicked();

private:
    Ui::MainWindow * ui_;
    Connector * connector_;
    PeopleModel * peopleModel_;

};
#endif // MAINWINDOW_H
