#ifndef COMPOSITEPAINTER_H_INCLUDED
#define COMPOSITEPAINTER_H_INCLUDED

#include <QGraphicsItem>
#include "Graphics.h"
#include "gui.h"
#include "PaintVisitor.h"

class CompositePainter : public QGraphicsItem
{
public:
    CompositePainter(Graphics *gr);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void SetGUI(gui *g);
    qreal posx;
    qreal posy;
    qreal width;
    qreal heigh;
    int _gridSpace;
private:
    gui *guiview;
    QPointF _location, _preLocation, _dragStart;
    Graphics *graphics;
};

#endif // COMPOSITEPAINTER_H_INCLUDED
