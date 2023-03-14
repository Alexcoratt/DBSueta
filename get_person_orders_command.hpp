#ifndef GET_PERSON_ORDERS_COMMAND_HPP
#define GET_PERSON_ORDERS_COMMAND_HPP

#include "i_command.hpp"

class GetPersonOrdersCommand : public ICommand {
public:
    explicit inline GetPersonOrdersCommand(std::size_t person_id) : person_id_(person_id) {}
    inline ~GetPersonOrdersCommand() {}
    QSqlError const execute(IReceiver *, Connector const *);

private:
    std::size_t person_id_;
};

#endif // GET_PERSON_ORDERS_COMMAND_HPP
