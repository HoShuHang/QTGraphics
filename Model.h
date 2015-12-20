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
#include "GraphicsFactory.h"
#include "DescriptionVisitor.h"

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
    void up();
    void down();
    int select(int x, int y);
    void select(int x, int y, int moveX, int moveY);
    bool isGraphicsSelect();
    bool isComposeEnable();
    bool isDecomposeEnable();
    bool isUpEnable();
    bool isDownEnable();
    void buildGraphicFromFile(const char *path);
    string getDescription();
    void MousePressEvent(int x, int y);
    void MouseMoveEvent(int x, int y);
    void MouseReleseEvent(int x, int y);
private:
    vector<Graphics *> *graphics;
    CommandManager *cm;
    vector<int> getSelects();
    int moveAtIndex;
    int iniX, iniY, moveX, moveY;
    Graphics *selectToUpDown;
};

#endif // MODEL_H_INCLUDED
