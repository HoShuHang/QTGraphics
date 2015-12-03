#include "Model.h"

void Model::createCircle()
{
    Graphics *g = new SimpleGraphics(new Circle(50, 0, 50));
    cm.createCommand(graphics, g);
}

void Model::createRectangle()
{
    Graphics *g = new SimpleGraphics(new Rectangle(0, 0, 100, 50));
    cm.createCommand(graphics, g);
}

void Model::createSquare()
{
    Graphics *g = new SimpleGraphics(new Square(50, 0, 50));
    cm.createCommand(graphics, g);
}

vector<Graphics *> *Model::getGraphics()
{
    return graphics;
}

void Model::undo()
{
    cm.Undo();
}

void Model::redo()
{
    cm.Redo();
}

bool Model::isUndoEnable()
{
    return cm.isUndoEmpty();
}

bool Model::isRedoEnable()
{
    return cm.isRedoEmpty();
}
