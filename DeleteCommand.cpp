#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(vector<Graphics *> *g_vector, vector<int> i)
{
    graphics = g_vector;
    indexs = i;
    g_obj = new vector<Graphics *>;
}

void DeleteCommand::Excute()
{
    for(int i = 0; i < indexs.size(); i ++)
    {
        g_obj->push_back(graphics->at(i));
        graphics->erase(graphics->begin() + indexs.at(i));
    }
}

void DeleteCommand::UnExcute()
{
    for(int i = 0; i < indexs.size(); i ++)
    {
        Graphics *graphic = g_obj->at(i);
        graphics->insert(graphics->begin() + indexs.at(i), graphic);
    }
}
