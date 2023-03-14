#include "delete_person_command.hpp"

DeletePersonCommand::DeletePersonCommand(unsigned id) : id_(id) {}
DeletePersonCommand::~DeletePersonCommand() {}

QSqlError const DeletePersonCommand::execute(IReceiver * receiver, Connector const * connector) {
    QString temp("CALL delete_person('%1');");
    QString qry = temp.arg(id_);

    QSqlQuery query = connector->sendQuery(qry);
    receiver->apply(&query);

    return query.lastError();
}
