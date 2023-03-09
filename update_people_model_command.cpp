#include "update_people_model_command.hpp"

UpdatePeopleModelCommand::UpdatePeopleModelCommand(QDate const & date, QString const & mode) :
    date_(date), mode_(mode) {}

UpdatePeopleModelCommand::~UpdatePeopleModelCommand() {}

QSqlError const UpdatePeopleModelCommand::execute(IReceiver * receiver, Connector const * connector) {
    QString temp("CALL get_people('%1', '%2');");
    QString qry = temp.arg(date_.toString("yyyy-MM-dd"), mode_);

    QSqlQuery query = connector->sendQuery(qry);
    receiver->apply(&query);

    return query.lastError();
}
