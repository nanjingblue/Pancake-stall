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

signals:
    void CostChanged(float value);

public:
    static int QriginalCake;
    static int Sauce;
    static int Cilantro;
    static int Egg;
    static int Crispbread;
    static int Ham;
    static int Potato;
    static int Youtiao;
    static int Loin;
private:
    float c_cost = 0;

};

#endif // CAKE_H
