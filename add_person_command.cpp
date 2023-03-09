#include <QDate>
#include "add_person_command.hpp"

AddPersonCommand::AddPersonCommand(
        QString & login, QString & name, QString & bio, QDate & birthdate, QString & sex
        ) : login_(login), name_(name), bio_(bio), birthdate_(birthdate), sex_(sex) {}

AddPersonCommand::~AddPersonCommand() {}

QSqlError const AddPersonCommand::execute(IReceiver * receiver, Connector const * connector) {
    QString temp("CALL add_person('%1', '%2', '%3', '%4', '%5');");
    QString qry = temp.arg(login_, name_, bio_, birthdate_.toString("yyyy-MM-dd"), sex_);

    QSqlQuery query = connector->sendQuery(qry);
    receiver->apply(&query);

    return query.lastError();
}
