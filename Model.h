#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <vector>
#include "Graphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

class Model
{
public:
    void createCircle();
    void createRectangle();
    void createSquare();
    vector<Graphics *> getGraphics();
private:
    vector<Graphics *> graphics;
};

#endif // MODEL_H_INCLUDED
