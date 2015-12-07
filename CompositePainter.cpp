#include "CompositePainter.h"

CompositePainter::CompositePainter(Graphics *gr)
{
    graphics = gr;
    posx = gr->getBoundingBox().llx();
    posy = gr->getBoundingBox().lly();
    width = gr->getBoundingBox().urx() - gr->getBoundingBox().llx();
    heigh = gr->getBoundingBox().ury() - gr->getBoundingBox().lly();
    _gridSpace = 10;
}

QRectF CompositePainter::boundingRect() const
{
    return QRectF(posx,posy,width,heigh);
}

void CompositePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    PaintVisitor pv(painter);
    graphics->accept(pv);
}

void CompositePainter::SetGUI(gui *g)
{
    guiview = g;
}
