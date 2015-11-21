#include "RectanglePainter.h"

RectanglePainter::RectanglePainter( qreal ll_x, qreal ll_y, qreal _width, qreal _heigh,QWidget *_widget)
{
    //ctor
    posx = ll_x;
    posy = ll_y;
    width = _width;
    heigh = _heigh;
    widget = _widget;
}

RectanglePainter::~RectanglePainter()
{
    //dtor
}

QRectF RectanglePainter::boundingRect() const
{
    return QRectF(posx,posy,width,heigh);
}

void RectanglePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    QPen rPen(Qt::red);
    QPen gPen(Qt::green);
    if(isComposite)
        painter->setPen(gPen);
    else
        painter->setPen(rPen);
    painter->drawRect(posx, posy, width, heigh);
}

void RectanglePainter::SetComposite(bool isC)
{
    isComposite = isC;
}
