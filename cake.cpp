#include "cake.h"

Cake::Cake(QObject *parent) : QObject(parent)
{

}

float Cake::Cost()
{
    return this->c_cost;
}

void Cake::setCost(float value)
{
    this->c_cost += value;
    emit(this->CostChanged(this->c_cost));
}

void Cake::setC_Cost(float value)
{
    this->c_cost = value;
}
