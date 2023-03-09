#ifndef I_MODEL_H
#define I_MODEL_H

#include <QSqlQueryModel>
#include <QSqlQuery>

class IModel {
public:
    virtual ~IModel() {};
    virtual QSqlQueryModel * get() = 0;
};

#endif // I_MODEL_H
