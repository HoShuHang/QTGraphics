#ifndef SIMPLEGRAPHICS_H_INCLUDED
#define SIMPLEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include "Shape.h"
#include <iostream>

class SimpleGraphics : public Graphics {
public:
    SimpleGraphics (Shape *shape_inst);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor &av);
    Shape * shape();
    void paint(QPainter *p);
    QGraphicsItem* createPainter(QWidget *w);
private:
    Shape * s;
};


#endif // SIMPLEGRAPHICS_H_INCLUDED
