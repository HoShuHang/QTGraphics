#include "Graphics.h"
#include "Rectangle.h"
#include <string>
#include "AreaVisitor.h"
#include "Painter.h"

Rectangle Graphics:: getBoundingBox() {return Rectangle(0,0,0,0);}
void Graphics::add(Graphics *g) {throw std::string("Cannot add child");}
void Graphics::accept(GraphicsVisitor & av) {}
Graphics::Graphics(){}
Graphics::~Graphics(){}
bool Graphics::isSelected()
{
    return selected;
}
void Graphics::setSelected(bool s)
{
    selected = s;
}
std::vector<Graphics *> *Graphics::getGraphics()
{
    throw std::string("Cannot add getGraphics");
}
