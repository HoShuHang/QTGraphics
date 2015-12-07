#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Shape.h"

class Square : public Shape {
public:
    Square(int ll_x, int ll_y, int length);
    int area();
    Rectangle getBoundingBox();
    std::string describe();
    QGraphicsItem* createPainter(QWidget *widget, bool isComposite);
    bool select(int x, int y);
    void draw(QPainter * painter);
    void moveLocation(int mX, int mY);
    void onMove(int mx, int my);
private:
    int x, y;
    int l;

};


#endif // SQUARE_H_INCLUDED
