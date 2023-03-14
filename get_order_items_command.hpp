#ifndef GET_ORDER_ITEMS_COMMAND_HPP
#define GET_ORDER_ITEMS_COMMAND_HPP

#include "i_command.hpp"

class GetOrderItemsCommand : public ICommand {
public:
    explicit inline GetOrderItemsCommand(std::size_t order_id) : order_id_(order_id) {}
    inline ~GetOrderItemsCommand() {}
    QSqlError const execute(IReceiver *, Connector const *);

private:
    std::size_t order_id_;
};

#endif // GET_ORDER_ITEMS_COMMAND_HPP
