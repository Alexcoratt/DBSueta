#ifndef UPDATE_PEOPLE_MODEL_COMMAND_HPP
#define UPDATE_PEOPLE_MODEL_COMMAND_HPP

#include <QSqlError>
#include <QDate>
#include "i_command.hpp"
#include "i_receiver.hpp"
#include "connector.hpp"

class UpdatePeopleModelCommand : public ICommand {
public:
    UpdatePeopleModelCommand(QDate const &, QString const &);
    ~UpdatePeopleModelCommand();
    QSqlError const execute(IReceiver *, Connector const *);

private:
    QDate const & date_;
    QString const & mode_;
};


#endif // UPDATE_PEOPLE_MODEL_COMMAND_HPP
