#include "DeleteCommand.h"

#include <iostream>
using namespace std;

DeleteCommand::DeleteCommand(vector<Graphics *> *g_vector, vector<int> i)
{
    graphics = g_vector;
    indexs = i;
    g_obj = new vector<Graphics *>;
    count = 0;
}

void DeleteCommand::Excute()
{
    for(int i = 0; i < indexs.size(); i ++)
    {
        g_obj->push_back(graphics->at(i));
    }
    for(int i = 0; i < g_obj->size(); i++)
    {
        graphics->erase((remove(graphics->begin(), graphics->end(), g_obj->at(i))), graphics->end());
    }
}

void DeleteCommand::UnExcute()
{
    for(int i = 0; i < indexs.size(); i ++)
    {
        Graphics *graphic = g_obj->at(i);
        cout << "i = " << i << endl;
        if(graphics->size() == 0)
            graphics->push_back(graphic);
        else
            graphics->insert(graphics->begin() + indexs.at(i), graphic);
    }
    while(g_obj->size()!=0)
        g_obj->pop_back();
}
