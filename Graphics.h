#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <QPen>
#include <QGraphicsItem>
#include <QWidget>

class Rectangle;
class GraphicsVisitor;

class Graphics {
public:
    virtual ~Graphics();
    virtual Rectangle getBoundingBox();
    virtual void add(Graphics *g);
    virtual void accept(GraphicsVisitor & av);
    virtual void paint(QPainter *p)=0;
protected:
    Graphics();
};

#endif // GRAPHICS_H_INCLUDED
