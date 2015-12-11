#ifndef RECTANGLEPAINTER_H_INCLUDED
#define RECTANGLEPAINTER_H_INCLUDED
#include <QPen>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include "Graphics.h"
class RectanglePainter:public QGraphicsItem
{
public:
    RectanglePainter( qreal ll_x, qreal ll_y, qreal _width, qreal _heigh,QWidget *_widget);
    virtual ~RectanglePainter();

    QWidget *widget;
    const QRectF *rectptr;
    qreal posx;
    qreal posy;
    qreal width;
    qreal heigh;
    QRectF boundingRect() const;//�����갵��virtual function�A���ثe�Τ���
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    QPointF _location, _dragStart;;
};

#endif // RECTANGLEPAINTER_H_INCLUDED
