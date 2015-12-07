#ifndef GRAPHICSSCENE_H_INCLUDED
#define GRAPHICSSCENE_H_INCLUDED

#include <QGraphicsScene>

class gui;

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene(gui *g, QRect rect);
protected:
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mousePressEvent (QGraphicsSceneMouseEvent * event );
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );
private:
    gui *guiview;
};

#endif // GRAPHICSSCENE_H_INCLUDED
