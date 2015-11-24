#include "PaintVisitor.h"
PaintVisitor::PaintVisitor()
{
}

void PaintVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
    items.push_back(s->createPainter(widget));
}

void PaintVisitor::visitCompositeGraphics(CompositeGraphics *cg)
{
    items.push_back(cg->createPainter(widget));
}

std::vector<QGraphicsItem *> PaintVisitor::getGraphics()
{
    return items;
}

void PaintVisitor::setWidget(QWidget *w)
{
    widget = w;
}
