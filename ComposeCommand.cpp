#include "ComposeCommand.h"
#include <iostream>

ComposeCommand::ComposeCommand(vector<Graphics *> *g, vector<int> i)
{
    graphics = g;
    indexs = i;
    g_obj = new vector<Graphics *>;
    compositeGraphic = new CompositeGraphics();
    for(int i = 0; i < indexs.size(); i ++)
    {
        Graphics *g = graphics->at(i);
        g_obj->push_back(g);
        compositeGraphic->add(g);
    }
    cout << "constructor" << endl;
}

void ComposeCommand::Excute()
{
    for(int i = 0; i < g_obj->size(); i++)
    {
        graphics->erase((remove(graphics->begin(), graphics->end(), g_obj->at(i))), graphics->end());
    }
    graphics->push_back(compositeGraphic);
}

void ComposeCommand::UnExcute()
{
    graphics->erase((remove(graphics->begin(), graphics->end(), compositeGraphic)), graphics->end());
    for(int i = 0; i < indexs.size(); i ++)
    {
        Graphics *graphic = g_obj->at(i);
        if(graphics->size() == 0)
            graphics->push_back(graphic);
        else
            graphics->insert(graphics->begin() + indexs.at(i), graphic);
    }
}
