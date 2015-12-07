#include "Model.h"

Model::Model()
{
    cm = new CommandManager();
    graphics = new vector<Graphics *>;
}

void Model::createCircle()
{
    Graphics *g = new SimpleGraphics(new Circle(-255, -5, 50));
    cm->createCommand(graphics, g);
}

void Model::createRectangle()
{
    Graphics *g = new SimpleGraphics(new Rectangle(0, 0, 100, 50));
    cm->createCommand(graphics, g);
}

void Model::createSquare()
{
    Graphics *g = new SimpleGraphics(new Square(50, 0, 50));
    cm->createCommand(graphics, g);
}

vector<Graphics *> *Model::getGraphics()
{
    return graphics;
}

void Model::undo()
{
    cm->Undo();
}

void Model::redo()
{
    cm->Redo();
}

bool Model::isUndoEnable()
{
    return cm->isUndoEmpty();
}

bool Model::isRedoEnable()
{
    return cm->isRedoEmpty();
}

void Model::deleteGraphics()
{
    for(int i = graphics->size()-1; i > 0; i--)
    {
        Graphics *g = graphics->at(i);
        if(g->isSelected())
        {
            cm->deleteCommand(graphics, i);
            break;
        }
    }
}

int Model::select(int x, int y)
{
    for(int i = graphics->size() - 1; i>=0; i--)
    {
        if(graphics->at(i)->select(x,y))
            return i;
    }
    return -1;
}

bool Model::isGraphicsSelect()
{
    for(int i = graphics->size()-1; i > 0; i--)
    {
        Graphics *g = graphics->at(i);
        if(g->isSelected())
        {
            return true;
        }
    }
    return false;
}

void Model::moveGraphic(Graphics *g, int mX, int mY)
{
    cm->moveCommand(g, mX, mY);
}
