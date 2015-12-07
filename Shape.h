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
    virtual QGraphicsItem* createPainter(QWidget *widget, bool isComposite)=0;
    virtual bool select(int x, int y)=0;
    virtual void draw(QPainter * painter)=0;
    virtual void moveLocation(int mX, int mY)=0;
};


#endif // SHAPE_H_INCLUDED
