#ifndef I_RECEIVER_HPP
#define I_RECEIVER_HPP

#include <QSqlQuery>

class IReceiver {
public:
    virtual void apply(QSqlQuery const *) = 0;
};

#endif // I_RECEIVER_HPP
