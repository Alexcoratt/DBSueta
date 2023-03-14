#include "model.hpp"

Model::Model() : model_(new QSqlQueryModel()) {}
Model::~Model() { delete model_; }
QSqlQueryModel * Model::get() { return model_; }

void Model::apply(QSqlQuery const * answerQuery) { model_->setQuery(*answerQuery); }
