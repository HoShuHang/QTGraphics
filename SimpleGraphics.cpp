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
    bool s = shape()->select(x,y);
//    if(s)
//        selected = !selected;
    return s;
}

bool SimpleGraphics::selectToUpDown(int x, int y)
{
    if(select(x,y))
        setSelectToUpDown(!getSelectToUpDown());
    return select(x,y);
}


void SimpleGraphics::draw(QPainter * painter)
{
    QPen pen(Qt::black);
    QBrush background (QColor::fromRgb(91,155,213), Qt::SolidPattern);
    pen.setWidth(2);
    if(getSelectToUpDown())
        pen.setColor(Qt::red);
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->setBrush( background);
    painter->setPen(pen);
    shape()->draw(painter);
}

void SimpleGraphics::moveLocation(int x, int y)
{
    shape()->moveLocation(x,y);
}

void SimpleGraphics::onMove(int x, int y)
{
    shape()->onMove(x, y);
}

int SimpleGraphics::getOnMoveX()
{
    return shape()->getOnMoveX();
}

int SimpleGraphics::getOnMoveY()
{
    return shape()->getOnMoveY();
}

bool SimpleGraphics::isComposite()
{
    return false;
}

void SimpleGraphics::setSelectToUpDown(bool s)
{
    selectTUD = s;
}

bool SimpleGraphics::getSelectToUpDown()
{
    return selectTUD;
}

bool SimpleGraphics::getSimpleSelectToUpDown()
{
    return selectTUD;
}

bool SimpleGraphics::canUp()
{
    return false;
}

bool SimpleGraphics::canDown()
{
    return false;
}
