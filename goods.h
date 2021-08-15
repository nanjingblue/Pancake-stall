#ifndef GOODS_H
#define GOODS_H

#include <QObject>

struct Goods {
    int Sales;
    int Inventory;
};

class Goods : public QObject
{
    Q_OBJECT
public:
    explicit Goods(QObject *parent = nullptr);

signals:

};

#endif // GOODS_H
