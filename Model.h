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
    void createCircle();
    void createRectangle();
    void createSquare();
    vector<Graphics *> *getGraphics();
    void undo();
    void redo();
    bool isUndoEnable();
    bool isRedoEnable();
private:
    vector<Graphics *> *graphics = new vector<Graphics *>;
    CommandManager cm;
};

#endif // MODEL_H_INCLUDED
