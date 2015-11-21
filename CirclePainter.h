#ifndef CIRCLEPAINTER_H_INCLUDED
#define CIRCLEPAINTER_H_INCLUDED
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
class CirclePainter:public QGraphicsItem
{
    public:
        CirclePainter( qreal cx, qreal cy, qreal r, QWidget *_widget);
        virtual ~CirclePainter();

        QWidget *widget;
        const QRectF *rectptr;
        qreal centerX;
        qreal centerY;
        qreal radius;
        QRectF boundingRect() const;//必須實做的virtual function，但目前用不到
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
        void SetComposite(bool isC);
    private:
        bool isComposite = false;
};

#endif // CIRCLEPAINTER_H_INCLUDED
