#include "cake.h"

Cake::Cake(QObject *parent) : QObject(parent)
{

}

int Cake::Cost()
{
    return this->c_cost;
}

void Cake::setCost(int value)
{
    this->c_cost += value;
    emit(this->CostChanged(this->c_cost));
}

int Cake::QriginalCake = 3;
int Cake::Sauce = 0;
int Cake::Cilantro = 0;
int Cake::Egg = 1;
int Cake::Crispbread = 1;
int Cake::Ham = 1;
int Cake::Potato = 1;
int Cake::Youtiao = 1;
int Cake::Loin = 1;
