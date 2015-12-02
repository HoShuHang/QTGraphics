#include "Model.h"

void Model::createCircle()
{
    Graphics *g = new SimpleGraphics(new Circle(50, 0, 50));
    graphics.push_back(g);
}

void Model::createRectangle()
{
    Graphics *g = new SimpleGraphics(new Rectangle(0, 0, 100, 50));
    graphics.push_back(g);
}

void Model::createSquare()
{
    Graphics *g = new SimpleGraphics(new Square(50, 0, 50));
    graphics.push_back(g);
}

vector<Graphics *> Model::getGraphics()
{
    return graphics;
}
