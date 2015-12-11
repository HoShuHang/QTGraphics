#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class Rectangle;

class Shape {
public:
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual std::string describe() {return std::string("");};
    virtual bool select(int x, int y)=0;
    virtual void draw(QPainter * painter)=0;
    virtual void moveLocation(int mX, int mY)=0;
    virtual void onMove(int mx, int my)=0;
    int getOnMoveX(){return moveX;};
    int getOnMoveY(){return moveY;};
protected:
    int moveX, moveY;
};


#endif // SHAPE_H_INCLUDED
