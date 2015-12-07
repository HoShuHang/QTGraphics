#include "CompositeGraphics.h"
#include <algorithm>
#include "Rectangle.h"
#include "GraphicsVisitor.h"
#include "AreaVisitor.h"

//can delete
#include <iostream>
#include "DescriptionVisitor.h"
#include "CompositePainter.h"

CompositeGraphics::CompositeGraphics() {}
void CompositeGraphics::add(Graphics *g)
{
    g_obj.push_back(g);
}
Rectangle CompositeGraphics::getBoundingBox()
{
    if (g_obj.size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i!=g_obj.end(); ++i)
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
    for (i=g_obj.begin(); i != g_obj.end(); ++i){
        (*i)->accept(av);
    }
    av.leave();
}

QGraphicsItem* CompositeGraphics::createPainter()
{
//    return getBoundingBox().createPainter(w, true);
    return new CompositePainter(this);
}

bool CompositeGraphics::select(int x, int y)
{
    selected = getBoundingBox().select(x, y);
    return selected;
}

void CompositeGraphics::draw(QPainter * painter)
{
    painter->drawRect(getBoundingBox().llx(), getBoundingBox().lly(), getBoundingBox().urx() - getBoundingBox().llx(), getBoundingBox().ury() - getBoundingBox().lly());
}
void CompositeGraphics::moveLocation(int x, int y)
{
    getBoundingBox().moveLocation(x,y);
    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i != g_obj.end(); ++i){
        (*i)->moveLocation(x,y);
    }
}
void CompositeGraphics::onMove(int x, int y)
{
    getBoundingBox().onMove(x, y);
    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i != g_obj.end(); ++i){
        (*i)->onMove(x, y);
    }
}
