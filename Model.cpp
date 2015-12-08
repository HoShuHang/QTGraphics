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
    vector<int> indexs = getSelects();
    cm->deleteCommand(graphics, indexs);
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
    vector<int> indexs = getSelects();
    return !indexs.empty();
}

void Model::moveGraphic(Graphics *g, int mX, int mY)
{
    cm->moveCommand(g, mX, mY);
}

void Model::composeGraphic()
{
    vector<int> indexs = getSelects();
    cm->composeCommand(graphics, indexs);
}

void Model::decomposeGraphic()
{
    vector<int> indexs = getSelects();
    Graphics *g = graphics->at(indexs.back());
    cm->decomposeCommand(graphics, g);
}

bool Model::isComposeEnable()
{
    return getSelects().size() >= 2;
}

bool Model::isDecomposeEnable()
{
    vector<int> indexs = getSelects();
    return indexs.size() == 1 && graphics->at(indexs.back())->isComposite();
}

vector<int> Model::getSelects()
{
    vector<int> indexs;
    for(int i = 0; i < graphics->size(); i++)
    {
        Graphics *g = graphics->at(i);
        if(g->isSelected())
        {
            indexs.push_back(i);
        }
    }
    return indexs;
}
