#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>
#include "RectanglePainter.h"

Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length)
{
    moveX = 0;
    moveY = 0;
}
int Square::area()
{
    return l*l;
}
Rectangle Square::getBoundingBox()
{
    return Rectangle(x,y,l,l);
}
std::string Square::describe()
{
    std::ostringstream oss;
    oss << "S(" << x <<"," << y << "," << l <<")";
    return oss.str();
}

QGraphicsItem* Square::createPainter(QWidget *widget, bool isComposite)
{
    RectanglePainter* item = new RectanglePainter(x, y, l, l, widget);
    item->SetComposite(isComposite);
    return item;
}

bool Square::select(int x, int y)
{
    if(x >= this->x && x <= this->x + this->l && y <= this->y + this->l && y >= this->y)
        return true;
    return false;
}

void Square::draw(QPainter * painter)
{
    painter->drawRect(x+moveX, y+moveY, l, l);
}

void Square::moveLocation(int mX, int mY)
{
    x += mX;
    y += mY;
}
void Square::onMove(int mx, int my)
{
    moveX = mx;
    moveY = my;
}
