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
    QGraphicsItem* createPainter();
    bool select(int x, int y);
    void draw(QPainter * painter);
    void moveLocation(int x, int y);
    void onMove(int x, int y);
    int getOnMoveX();
    int getOnMoveY();
    bool isComposite();
    void select(int x, int y, int moveX, int moveY);
private:
    Shape * s;
};


#endif // SIMPLEGRAPHICS_H_INCLUDED
