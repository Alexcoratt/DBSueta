#ifndef MODEL_H
#define MODEL_H

#include "i_model.hpp"
#include "i_receiver.hpp"

class Model : public IModel, public IReceiver{
public:
    Model();

    // IModel implemented methods
    ~Model();
    QSqlQueryModel * get();

    // IReceiver implemented methods
    void apply(QSqlQuery const *);

private:
        QSqlQueryModel * model_;
};

#endif // MODEL_H
