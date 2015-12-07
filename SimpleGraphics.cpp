#include "SimpleGraphics.h"
#include "Rectangle.h"
#include "AreaVisitor.h"
#include "CompositePainter.h"

SimpleGraphics::SimpleGraphics (Shape *shape_inst):s(shape_inst) {}
Rectangle SimpleGraphics::getBoundingBox()
{
    return s->getBoundingBox();
}
void SimpleGraphics::accept(GraphicsVisitor &av)
{
    av.visitSimpleGraphics(this);
}
Shape * SimpleGraphics::shape()
{
    return s;
}
QGraphicsItem* SimpleGraphics::createPainter()
{
    return new CompositePainter(this);
}
bool SimpleGraphics::select(int x, int y)
{
    selected = shape()->select(x,y);
    return selected;
}

void SimpleGraphics::draw(QPainter * painter)
{
    shape()->draw(painter);
}

void SimpleGraphics::moveLocation(int x, int y)
{
    cout << "simplegraphic";
    shape()->moveLocation(x,y);
}
void SimpleGraphics::onMove(int x, int y)
{
    shape()->onMove(x, y);
}
