#include "PaintVisitor.h"
PaintVisitor::PaintVisitor()
{
}

void PaintVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
    items.push_back(new Painter(s, widget));
//    qGraphicsScene->addItem(s->createPainter(widget));
}

void PaintVisitor::visitCompositeGraphics(CompositeGraphics *cg)
{
    items.push_back(new Painter(cg, widget));
//    qGraphicsScene->addItem(cg->createPainter(widget));
}

std::vector<QGraphicsItem *> PaintVisitor::getGraphics()
{
    return items;
}

void PaintVisitor::setWidget(QWidget *w)
{
    widget = w;
}
