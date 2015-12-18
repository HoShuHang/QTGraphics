#include "CompositeGraphics.h"
#include <algorithm>
#include "Rectangle.h"
#include "GraphicsVisitor.h"
#include "AreaVisitor.h"

//can delete
#include <iostream>
#include "DescriptionVisitor.h"
#include "CompositePainter.h"

CompositeGraphics::CompositeGraphics()
{
    moveX = 0;
    moveY = 0;
    g_obj = new vector<Graphics *>;
}
void CompositeGraphics::add(Graphics *g)
{
    g_obj->push_back(g);
}
Rectangle CompositeGraphics::getBoundingBox()
{
    if (g_obj->size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i=g_obj->begin(); i!=g_obj->end(); ++i)
    {
        minx.push_back((*i)->getBoundingBox().llx());
        miny.push_back((*i)->getBoundingBox().lly());
        maxx.push_back((*i)->getBoundingBox().urx());
        maxy.push_back((*i)->getBoundingBox().ury());
    }
    int llx = *min_element(minx.begin(),minx.end());
    int lly = *min_element(miny.begin(),miny.end());
    int urx = *max_element(maxx.begin(),maxx.end());
    int ury = *max_element(maxy.begin(),maxy.end());

    return Rectangle(llx,lly,urx-llx,ury-lly);
}

void CompositeGraphics::accept(GraphicsVisitor & av)
{
    av.visitCompositeGraphics(this);
    av.enter();
    std::vector<Graphics *>::iterator i;
    for (i=g_obj->begin(); i != g_obj->end(); ++i)
    {
        (*i)->accept(av);
    }
    av.leave();
}

QGraphicsItem* CompositeGraphics::createPainter()
{
    return new CompositePainter(this);
}

bool CompositeGraphics::select(int x, int y)
{
    cout << "composite select" << endl;
    bool s = getBoundingBox().select(x,y);
    return s;
}

bool CompositeGraphics::selectToUpDown(int x, int y)
{
    std::vector<Graphics *>::iterator i;
    for (i=g_obj->begin(); i != g_obj->end(); ++i)
    {
        (*i)->setSelectToUpDown(false);
    }
    for (i=g_obj->begin(); i != g_obj->end(); ++i)
    {
        if((*i)->select(x,y))
        {
            (*i)->setSelectToUpDown(!(*i)->getSelectToUpDown());
            return true;
        }
    }
    return false;
}

void CompositeGraphics::draw(QPainter * painter)
{
    QPen pen(Qt::green);
    pen.setWidth(2);
    if(getSelectToUpDown())
        pen.setColor(Qt::red);
    QBrush background (Qt::transparent, Qt::SolidPattern);
    painter->setBrush(background);
    painter->setPen(pen);
    painter->drawRect(getBoundingBox().llx()+moveX, getBoundingBox().lly()+moveY, getBoundingBox().urx() - getBoundingBox().llx(), getBoundingBox().ury() - getBoundingBox().lly());
}

void CompositeGraphics::moveLocation(int x, int y)
{
    getBoundingBox().moveLocation(x,y);
    std::vector<Graphics *>::iterator i;
    for (i=g_obj->begin(); i != g_obj->end(); ++i)
    {
        (*i)->moveLocation(x,y);
    }
}

void CompositeGraphics::onMove(int x, int y)
{
    getBoundingBox().onMove(x, y);
    std::vector<Graphics *>::iterator i;
    moveX = x;
    moveY = y;
    for (i=g_obj->begin(); i != g_obj->end(); ++i)
    {
        (*i)->onMove(x, y);
    }
}

int CompositeGraphics::getOnMoveX()
{
    return moveX;
}

int CompositeGraphics::getOnMoveY()
{
    return moveY;
}

std::vector<Graphics *> *CompositeGraphics::getGraphics()
{
    return g_obj;
}

bool CompositeGraphics::isComposite()
{
    return true;
}

void CompositeGraphics::setSelectToUpDown(bool s)
{
    selectTUD = s;
}

bool CompositeGraphics::getSelectToUpDown()
{
    if(selectTUD)
        return true;
    else
    {
        for(int i = g_obj->size() - 1; i >= 0; i--)
        {
            Graphics *g = g_obj->at(i);
            if(g->getSimpleSelectToUpDown())
                return true;
        }
    }
    return false;
}

bool CompositeGraphics::getSimpleSelectToUpDown()
{
    return false;
}

bool CompositeGraphics::canUp()
{
    if(g_obj->at(0)->getSelectToUpDown())
        return false;
    return true;
}

bool CompositeGraphics::canDown()
{
    if(g_obj->at(g_obj->size() - 1)->getSelectToUpDown())
        return false;
    return true;
}
