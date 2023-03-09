#ifndef PEOPLE_MODEL_HPP
#define PEOPLE_MODEL_HPP

#include "i_model.hpp"
#include "i_receiver.hpp"

class PeopleModel : public IModel, public IReceiver{
public:
    PeopleModel();

    // IModel implemented methods
    ~PeopleModel();
    QSqlQueryModel * get();

    // IReceiver implemented methods
    void apply(QSqlQuery const *);

private:
        QSqlQueryModel * model_;
};

#endif // PEOPLE_MODEL_HPP
