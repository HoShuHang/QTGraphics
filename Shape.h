#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include "RectanglePainter.h"
#include "CirclePainter.h"

class Rectangle;

class Shape {
public:
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual std::string describe() {return std::string("");};
    virtual void paint(QPainter *p)=0;
    virtual QGraphicsItem* createPainter(QWidget *widget, bool isComposite)=0;
};


#endif // SHAPE_H_INCLUDED
