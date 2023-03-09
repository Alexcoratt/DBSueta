#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

#include <QSqlDatabase>

class Connector {
public:
    Connector();
    ~Connector();

    bool connect(QString, QString, QString, QString);
    QSqlQuery sendQuery(QString) const;
    QString getLastError() const;

private:
    QSqlDatabase * db_;
};

#endif // CONNECTOR_HPP
