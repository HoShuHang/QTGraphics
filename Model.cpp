#include "Model.h"

void Model::createCircle()
{
    Graphics *g = new SimpleGraphics(new Circle(50, 0, 50));
//    graphics.push_back(g);
    Command *c = new CreateCommand(graphics, g);
    c->Excute();
}

void Model::createRectangle()
{
    Graphics *g = new SimpleGraphics(new Rectangle(0, 0, 100, 50));
//    graphics.push_back(g);
    Command *c = new CreateCommand(graphics, g);
    c->Excute();
}

void Model::createSquare()
{
    Graphics *g = new SimpleGraphics(new Square(50, 0, 50));
//    graphics.push_back(g);
    Command *c = new CreateCommand(graphics, g);
    c->Excute();
}

vector<Graphics *> *Model::getGraphics()
{
    return graphics;
}

void Model::undo()
{
    Command::Undo();
}

void Model::redo()
{
    Command::Redo();
}
