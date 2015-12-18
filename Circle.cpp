#include "Circle.h"
#include "Rectangle.h"
#include <sstream>
#include <cmath>

const int PI=3;

Circle::Circle(int center_x, int center_y, int radius)
    :cx(center_x),cy(center_y),r(radius)
{
    moveX = 0;
    moveY = 0;
}
int Circle::area() {return PI*r*r;}
Rectangle Circle::getBoundingBox() {return Rectangle(cx-r,cy-r,2*r,2*r);}
std::string Circle::describe() {
    std::ostringstream oss;
    oss << "C(" << cx <<"," << cy << "," << r <<")";
    return oss.str();
}

bool Circle::select(int x, int y)
{
    int dis = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
    if(dis <= r)
        return true;
    return false;
}

void Circle::draw(QPainter * painter)
{
    QPoint p(cx+moveX, cy+moveY);
    painter->drawEllipse(p, r, r);
}

void Circle::moveLocation(int mX, int mY)
{
    cx+=mX;
    cy+=mY;
}
void Circle::onMove(int mx, int my)
{
    moveX = mx;
    moveY = my;
}
