#ifndef GOODS_H
#define GOODS_H

#include <QObject>

struct goods {
    int Sales = 0;
    int Inventory = 0;
};

class Goods : public QObject
{
    Q_OBJECT
public:
    explicit Goods(QObject *parent = nullptr);

signals:

};

#endif // GOODS_H
