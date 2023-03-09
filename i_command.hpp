#ifndef I_COMMAND_H
#define I_COMMAND_H

#include <QSqlQuery>
#include <QSqlError>
#include "i_receiver.hpp"
#include "connector.hpp"

class ICommand {
public:
    virtual ~ICommand() {};
    virtual QSqlError const execute(IReceiver *, Connector const *) = 0;
};

#endif // I_COMMAND_H
