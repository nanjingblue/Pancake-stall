#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int cost READ cost WRITE setCost NOTIFY costChanged)
public:
    explicit QPerson(QString username, QString password, QObject *parent = nullptr);
    int cost();
    void setCost(int value);

signals:
    void costChanged(int value);

protected:
    QString username;
    QString password;
    int m_cost = 0;
};

#endif // QPERSON_H
