#include "people_model.hpp"

PeopleModel::PeopleModel() : model_(new QSqlQueryModel()) {}
PeopleModel::~PeopleModel() { delete model_; }
QSqlQueryModel * PeopleModel::get() { return model_; }

void PeopleModel::apply(QSqlQuery const * answerQuery) { model_->setQuery(*answerQuery); }
