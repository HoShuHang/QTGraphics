#include "Model.h"

Model::Model()
{
    cm = new CommandManager();
    graphics = new vector<Graphics *>;
    moveAtIndex=0;
    iniX=0;
    iniY=0;
    moveX=0;
    moveY=0;
    loadFileEnable = true;
}

void Model::createCircle()
{
    Graphics *g = new SimpleGraphics(new Circle(50, 0, 50));
    cm->createCommand(graphics, g);
    NotifyDataChange();
}

void Model::createRectangle()
{
    Graphics *g = new SimpleGraphics(new Rectangle(0, 0, 100, 50));
    cm->createCommand(graphics, g);
    NotifyDataChange();
}

void Model::createSquare()
{
    Graphics *g = new SimpleGraphics(new Square(50, 0, 50));
    cm->createCommand(graphics, g);
    NotifyDataChange();
}

vector<Graphics *> *Model::getGraphics()
{
    return graphics;
}

void Model::undo()
{
    cm->Undo();
    NotifyDataChange();
}

void Model::redo()
{
    cm->Redo();
    NotifyDataChange();
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
    NotifyDataChange();
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
    return indexs.size() == 1;
}

void Model::moveGraphic(Graphics *g, int mX, int mY)
{
    cm->moveCommand(g, mX, mY);
}

void Model::composeGraphic()
{
    vector<int> indexs = getSelects();
    cm->composeCommand(graphics, indexs);
    NotifyDataChange();
}

void Model::decomposeGraphic()
{
    vector<int> indexs = getSelects();
    Graphics *g = graphics->at(indexs.back());
    cm->decomposeCommand(graphics, g);
    NotifyDataChange();
}

void Model::MousePressEvent(int x, int y)
{
    iniX = x;
    iniY = y;
    moveAtIndex = select(iniX, iniY);
    moveX = 0;
    moveY=0;
    NotifyDataChange();
}

void Model::MouseMoveEvent(int x, int y)
{
    moveX = (x - iniX);
    moveY = (y - iniY);
    if(moveAtIndex != -1)
    {
        Graphics *g = getGraphics()->at(moveAtIndex);
        g->onMove(moveX, moveY);
    }
    NotifyDataChange();
}

void Model::MouseReleseEvent(int x, int y)
{
    if(moveAtIndex != -1)
    {
        Graphics *g = getGraphics()->at(moveAtIndex);
        if(abs(moveX) > 1 || abs(moveY) > 1)
        {
            g->onMove(0, 0);
            g->setSelected(true);
            moveGraphic(g, moveX, moveY);
        }
        else
        {
            g->setSelected(!g->isSelected());
            if(g->selectToUpDown(x, y))
                selectToUpDown = g;
        }
    }
    else
    {
        if(moveX >= 0 && moveY >= 0)
            select(iniX, iniY, iniX + moveX, iniY + moveY);
        else if(moveX >= 0 && moveY < 0)
            select(iniX, iniY + moveY, iniX + moveX, iniY);
        else if(moveX < 0 && moveY < 0)
            select(iniX + moveX, iniY + moveY, iniX, iniY);
        else if(moveX < 0 && moveY >= 0)
            select(iniX + moveX, iniY, iniX, iniY + moveY);
    }
    NotifyDataChange();
}

void Model::up()
{
    cm->upCommand(selectToUpDown);
    NotifyDataChange();
}

void Model::down()
{
    cm->downCommand(selectToUpDown);
    NotifyDataChange();
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

bool Model::isUpEnable()
{
    std::vector<Graphics *>::iterator i;
    for(i = graphics->begin(); i!=graphics->end(); i++)
    {
        if((*i)->getSelectToUpDown() && (*i)->canUp())
            return true;
    }
    return false;
}

bool Model::isDownEnable()
{
    std::vector<Graphics *>::iterator i;
    for(i = graphics->begin(); i!=graphics->end(); i++)
    {
        if((*i)->getSelectToUpDown() && (*i)->canDown())
            return true;
    }
    return false;
}

bool Model::isLoadFileEnable()
{
    return loadFileEnable;
}

void Model::NotifyDataChange()
{
    loadFileEnable = false;
    Notify();
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

void Model::buildGraphicFromFile(const char *path)
{
    GraphicsFactory *gf = new GraphicsFactory();
    vector<Graphics *> *g = gf->buildGraphicsFromFile(path);
    for(int i = 0; i < g->size(); i++)
    {
        graphics->push_back(g->at(i));
    }
    cm->cleanUndoRedo();
//    cm->createCommand(graphics, g);
    NotifyDataChange();
    loadFileEnable = true;
}

string Model::getDescription()
{
    DescriptionVisitor dv;
    std::vector<Graphics *>::iterator i;
    for(i = graphics->begin(); i!=graphics->end(); i++)
    {
        (*i)->accept(dv);
    }
    return dv.getDescription();
}

void Model::select(int x, int y, int moveX, int moveY)
{
    std::vector<Graphics *>::iterator i;
    for(i = graphics->begin(); i!=graphics->end(); i++)
    {
        (*i)->setSelected(false);
    }
    for(i = graphics->begin(); i!=graphics->end(); i++)
    {
        bool s = false;
        for(int j = x; j <= moveX; j++)
        {
            for(int k = y; k <= moveY; k++)
            {
                if((*i)->select(j,k))
                {
                    s=true;
                    (*i)->setSelected(true);
                    break;
                }
            }
            if(s)
                break;
        }
    }
}

void Model::saveFile(const char *c_str)
{
    ofstream myfile (c_str);
    if (myfile.is_open())
    {
        myfile << getDescription();
        myfile.close();
    }
    NotifyDataChange();
    loadFileEnable = true;
}
