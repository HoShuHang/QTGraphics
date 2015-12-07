#include "GraphicsScene.h"
#include <iostream>
#include "gui.h"
using namespace std;

GraphicsScene::GraphicsScene(gui *g, QRect rect) : QGraphicsScene(rect)
{
    guiview = g;
}

void GraphicsScene::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    guiview -> mouseMoveEvent(event);
}

void GraphicsScene::mousePressEvent (QGraphicsSceneMouseEvent * event )
{
    guiview -> mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent (QGraphicsSceneMouseEvent * event )
{
    guiview -> mouseReleaseEvent(event);
}
