#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>

Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(x,y,l,l);}
std::string Square::describe() {
    std::ostringstream oss;
    oss << "S(" << x <<"," << y << "," << l <<")";
    return oss.str();
}

void Square::paint(QPainter *p)
{
    p->drawRect(x, y, l, l);
}

QGraphicsItem* Square::createPainter(QWidget *widget, bool isComposite)
{
    RectanglePainter* item = new RectanglePainter(x, y, l, l, widget);
    item->SetComposite(isComposite);
    return item;
}
