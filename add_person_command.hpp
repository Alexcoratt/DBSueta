#ifndef ADD_PERSON_COMMAND_HPP
#define ADD_PERSON_COMMAND_HPP

#include <QDate>
#include "i_command.hpp"

class AddPersonCommand : public ICommand {
public:
    AddPersonCommand(QString &, QString &, QString &, QDate &, QString &);
    ~AddPersonCommand();

    QSqlError const execute(IReceiver *, Connector const *);

private:
    QString & login_;
    QString & name_;
    QString & bio_;
    QDate & birthdate_;
    QString & sex_;
};


#endif // ADD_PERSON_COMMAND_HPP
