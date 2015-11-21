#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"
#include <QPoint>

class Circle : public Shape {
public:
    Circle(int center_x, int center_y, int radius);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    void paint(QPainter *p);
    //int perimeter();
private:
    int cx, cy;
    int r;
};

#endif // CIRCLE_H_INCLUDED
