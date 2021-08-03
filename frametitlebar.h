#ifndef FRAMETITLEBAR_H
#define FRAMETITLEBAR_H

#include <QFrame>
#include <QMouseEvent>

class FrameTitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit FrameTitleBar(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:

private:
    bool m_isPressed;
    QPoint m_startMovePos;

};

#endif // FRAMETITLEBAR_H
