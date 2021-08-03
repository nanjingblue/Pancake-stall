#include "frametitlebar.h"

FrameTitleBar::FrameTitleBar(QWidget *parent) : QFrame(parent)
{
    m_isPressed = false;
}

void FrameTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed) {
        QPoint movePoint = event->globalPos() - m_startMovePos;
        if (parentWidget()) {
            QPoint widgetPos = this->parentWidget()->pos();
            m_startMovePos = event->globalPos();
            parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y()+movePoint.y());
        }
    }
    return QFrame::mouseMoveEvent(event);
}

void FrameTitleBar::mousePressEvent(QMouseEvent *event)
{
    m_isPressed  = true;
    m_startMovePos = event->globalPos();
    return QFrame::mousePressEvent(event);
}

void FrameTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    return QFrame::mouseReleaseEvent(event);
}
