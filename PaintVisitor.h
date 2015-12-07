#ifndef PAINTVISITOR_H_INCLUDED
#define PAINTVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
#include <string>
#include <QGraphicsScene>
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "Painter.h"
#include <Qpainter>

class PaintVisitor : public GraphicsVisitor
{
public:
    PaintVisitor(QPainter *p);
    std::vector<QGraphicsItem *> getPainters();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
    void setWidget(QWidget *w);
private:
    QPainter *painter;
    QWidget *widget;
    std::vector<QGraphicsItem *> items;
};

#endif // PAINTVISITOR_H_INCLUDED
