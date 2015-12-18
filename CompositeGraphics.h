#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include <vector>
#include "GraphicsVisitor.h"

class CompositeGraphics : public Graphics {
public:
    CompositeGraphics();
    void add (Graphics *g);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor & av);
    QGraphicsItem* createPainter();
    bool select(int x, int y);
    void draw(QPainter * painter);
    void moveLocation(int x, int y);
    void onMove(int x, int y);
    int getOnMoveX();
    int getOnMoveY();
    std::vector<Graphics *> *getGraphics();
    bool isComposite();
    bool selectToUpDown(int x, int y);
    void setSelectToUpDown(bool s);
    bool getSelectToUpDown();
    bool getSimpleSelectToUpDown();
    bool canUp();
    bool canDown();
private:
    std::vector<Graphics *> *g_obj;
    int moveX, moveY;
};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
