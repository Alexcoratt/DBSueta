#include "get_person_orders_command.hpp"

QSqlError const GetPersonOrdersCommand::execute(IReceiver * receiver, Connector const * connector) {
    QString temp("CALL get_orders_of_person('%1');");
    QString qry = temp.arg(person_id_);

    QSqlQuery query = connector->sendQuery(qry);
    receiver->apply(&query);

    return query.lastError();
}
