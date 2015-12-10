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

    if(graphics->isSelected())
    {
        int radius = 2;
        QPoint ll(posx+graphics->getOnMoveX(), posy+graphics->getOnMoveY());
        QPoint lr(posx+graphics->getOnMoveX(), posy+heigh+graphics->getOnMoveY());
        QPoint ul(posx+width+graphics->getOnMoveX(), posy+graphics->getOnMoveY());
        QPoint ur(posx+width+graphics->getOnMoveX(), posy+heigh+graphics->getOnMoveY());
        painter->drawEllipse(ll, radius, radius);
        painter->drawEllipse(lr, radius, radius);
        painter->drawEllipse(ul, radius, radius);
        painter->drawEllipse(ur, radius, radius);
    }
}

void CompositePainter::SetGUI(gui *g)
{
    guiview = g;
}
