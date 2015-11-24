#include "CirclePainter.h"

CirclePainter::CirclePainter( qreal cx, qreal cy, qreal r, QWidget *_widget)
{
    //ctor
    centerX = cx;
    centerY = cy;
    radius = r;
    widget = _widget;
}

CirclePainter::~CirclePainter()
{
    //dtor
}

QRectF CirclePainter::boundingRect() const
{
    return QRectF(centerX,centerY,radius,radius);
}

void CirclePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    QPen rPen(Qt::blue);
    QPen gPen(Qt::green);
    if(isComposite)
        painter->setPen(gPen);
    else
        painter->setPen(rPen);
    QPoint point(centerX, centerY);
    painter->drawEllipse(point, radius, radius);
}

void CirclePainter::SetComposite(bool isC)
{
    isComposite = isC;
}
