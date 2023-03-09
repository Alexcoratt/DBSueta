#include <QSqlQuery>
#include <QSqlError>
#include "connector.hpp"

Connector::Connector() : db_(new QSqlDatabase()) { *db_ = QSqlDatabase::addDatabase("QMYSQL"); }
Connector::~Connector() { delete db_; }

bool Connector::connect(QString hostname, QString dbName, QString userName, QString pwd) {
    db_->setHostName(hostname);
    db_->setDatabaseName(dbName);
    db_->setUserName(userName);
    db_->setPassword(pwd);

    bool connected = db_->open();
    db_->close();
    return connected;
}

QSqlQuery Connector::sendQuery(QString strQuery) const {
    QSqlQuery query(*db_);
    db_->open();
    query.exec(strQuery);
    db_->close();
    return query;
}

QString Connector::getLastError() const { return QString(db_->lastError().text()); }
