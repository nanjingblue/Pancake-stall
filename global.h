#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = nullptr);

signals:

};

#endif // GLOBAL_H