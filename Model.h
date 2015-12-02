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
private:
    vector<Graphics *> *graphics = new vector<Graphics *>;
};

#endif // MODEL_H_INCLUDED
