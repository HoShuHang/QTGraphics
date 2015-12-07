#include "PaintVisitor.h"
PaintVisitor::PaintVisitor(QPainter *p)
{
    painter = p;
}

void PaintVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
//    items.push_back(s->createPainter(widget));
    QPen bPen(Qt::blue);
    painter->setPen(bPen);
    s->draw(painter);
}

void PaintVisitor::visitCompositeGraphics(CompositeGraphics *cg)
{
//    items.push_back(cg->createPainter(widget));
    QPen gPen(Qt::green);
    painter->setPen(gPen);
    cg->draw(painter);
}

std::vector<QGraphicsItem *> PaintVisitor::getPainters()
{
    return items;
}

void PaintVisitor::setWidget(QWidget *w)
{
    widget = w;
}
