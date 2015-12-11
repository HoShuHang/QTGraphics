#include "Rectangle.h"
#include <sstream>
#include <iostream>
#include "RectanglePainter.h"

Rectangle::Rectangle(int ll_x, int ll_y, int length, int width)
    :x(ll_x),y(ll_y),l(length),w(width)
{
    moveX = 0;
    moveY = 0;
}
int Rectangle::area()
{
    return l*w;
}
Rectangle Rectangle::getBoundingBox()
{
    return Rectangle(x,y,l,w);
}
std::string Rectangle::describe()
{
    std::ostringstream oss;
    oss << "R(" << x <<"," << y << "," << l << "," << w << ")";
    return oss.str();
}

bool Rectangle::select(int x, int y)
{
    if(x >= llx() && x <= urx() && y <= ury() && y >= lly())
        return true;
    return false;
}

void Rectangle::draw(QPainter * painter)
{
    painter->drawRect(x+moveX,y+moveY,l,w);
}

void Rectangle::moveLocation(int mX, int mY)
{
    x+=mX;
    y+=mY;
}
void Rectangle::onMove(int mx, int my)
{
    moveX = mx;
    moveY = my;
}
