#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <QPen>
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>

class Model;

class Rectangle;
class GraphicsVisitor;

class Graphics {
public:
    virtual ~Graphics();
    virtual Rectangle getBoundingBox();
    virtual void add(Graphics *g);
    virtual void accept(GraphicsVisitor & av);
    virtual QGraphicsItem* createPainter()=0;
    virtual bool select(int x, int y)=0;
    bool isSelected();
    void setSelected(bool s);
    virtual void draw(QPainter * painter)=0;
    virtual void moveLocation(int x, int y)=0;
    virtual void onMove(int x, int y)=0;
    virtual int getOnMoveX()=0;
    virtual int getOnMoveY()=0;
    virtual std::vector<Graphics *> *getGraphics();
    virtual bool isComposite()=0;
    virtual void setSelectToUpDown(bool s)=0;
    virtual bool selectToUpDown(int x, int y)=0;
    virtual bool getSelectToUpDown()=0;
    virtual bool getSimpleSelectToUpDown()=0;
    virtual bool canUp()=0;
    virtual bool canDown()=0;
protected:
    Graphics();
    bool selected = false;
    bool selectTUD = false;
};

#endif // GRAPHICS_H_INCLUDED
