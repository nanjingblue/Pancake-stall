#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
public:
    explicit QPerson(QObject *parent = nullptr);

signals:

};

#endif // QPERSON_H
