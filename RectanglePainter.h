#ifndef RECTANGLEPAINTER_H_INCLUDED
#define RECTANGLEPAINTER_H_INCLUDED
#include <QPen>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include "Graphics.h"
#include "gui.h"
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
    QRectF boundingRect() const;//必須實做的virtual function，但目前用不到
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void SetComposite(bool isC);
    void SetGUI(gui *g);
private:
    bool isComposite = false;
    gui *guiview;
    QPointF _location, _dragStart;;
};

#endif // RECTANGLEPAINTER_H_INCLUDED
