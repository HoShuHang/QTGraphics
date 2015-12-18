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
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
    void draw();
private:
    QPainter *painter;
    std::vector<Graphics *> items;
};

#endif // PAINTVISITOR_H_INCLUDED
