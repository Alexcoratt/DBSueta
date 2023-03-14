#include "get_order_items_command.hpp"

QSqlError const GetOrderItemsCommand::execute(IReceiver * receiver, Connector const * connector) {
    QString temp("CALL get_items_of_order('%1');");
    QString qry = temp.arg(order_id_);

    QSqlQuery query = connector->sendQuery(qry);
    receiver->apply(&query);

    return query.lastError();
}
