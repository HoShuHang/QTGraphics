#ifndef PAINTVISITOR_H_INCLUDED
#define PAINTVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
#include <string>
#include <QGraphicsScene>
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "Painter.h"

class PaintVisitor : public GraphicsVisitor
{
public:
    PaintVisitor();
//    PaintVisitor(QWidget *w);
    std::vector<QGraphicsItem *> getGraphics();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
    void setWidget(QWidget *w);
private:
    QWidget *widget;
    std::vector<QGraphicsItem *> items;
};

#endif // PAINTVISITOR_H_INCLUDED
