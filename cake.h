#ifndef CAKE_H
#define CAKE_H

#include <QObject>

class Cake : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Cost READ Cost WRITE setCost NOTIFY CostChanged)
public:
    explicit Cake(QObject *parent = nullptr);
    int Cost();
    void setCost(int);

signals:
    void CostChanged(int value);

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
    int c_cost = 0;

};

#endif // CAKE_H
