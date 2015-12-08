#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>
#include "Graphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Command.h"
#include "CreateCommand.h"
#include "CommandManager.h"

using namespace std;

class Model
{
public:
    Model();
    void createCircle();
    void createRectangle();
    void createSquare();
    vector<Graphics *> *getGraphics();
    void undo();
    void redo();
    bool isUndoEnable();
    bool isRedoEnable();
    void deleteGraphics();
    void moveGraphic(Graphics *g, int mX, int mY);
    void composeGraphic();
    void decomposeGraphic();
    int select(int x, int y);
    bool isGraphicsSelect();
private:
    vector<Graphics *> *graphics;
    CommandManager *cm;
};

#endif // MODEL_H_INCLUDED
