#include "Circle.h"
#include "Rectangle.h"
#include <sstream>
#include <cmath>
#include "CirclePainter.h"
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

QGraphicsItem* Circle::createPainter(QWidget *widget, bool isComposite)
{
    CirclePainter* item = new CirclePainter(cx, cy, r, widget);
    item->SetComposite(isComposite);
    return item;
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
    cout << "before move" << endl;
    cout << "mX = " << mX << endl;
    cout << "mY = " << mY << endl;
    cout << "cx = " << cx << endl;
    cout << "cy = " << cy << endl;
    cx+=mX;
    cy+=mY;
    cout << "cx = " << cx << endl;
    cout << "cy = " << cy << endl;
}
void Circle::onMove(int mx, int my)
{
    moveX = mx;
    moveY = my;
}
