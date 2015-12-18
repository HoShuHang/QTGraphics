#include "PaintVisitor.h"
PaintVisitor::PaintVisitor(QPainter *p)
{
    painter = p;
}

void PaintVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
    items.push_back(s);
}

void PaintVisitor::visitCompositeGraphics(CompositeGraphics *cg)
{
    items.push_back(cg);
}

void PaintVisitor::draw()
{
    for(int i = items.size() - 1; i >=0; i--)
    {
        Graphics *g = items.at(i);
        g->draw(painter);
    }
}
