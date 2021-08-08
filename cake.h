#ifndef CAKE_H
#define CAKE_H

#include <QObject>

class Cake : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float Cost READ Cost WRITE setCost NOTIFY CostChanged)
public:
    explicit Cake(QObject *parent = nullptr);
    float Cost();
    void setCost(float);
    void setC_Cost(float value);

signals:
    void CostChanged(float value);

public:
    int QriginalCake = 0;
    int Sauce = 0;
    int Cilantro = 0;
    int Egg = 0;
    int Crispbread = 0;
    int Ham = 0;
    int Potato = 0;
    int Youtiao = 0;
    int Loin = 0;
    int value[10] = {0};
private:
    float c_cost = 0;

};

#endif // CAKE_H
