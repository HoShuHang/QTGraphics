#include "DownCommand.h"

DownCommand::DownCommand(Graphics *g)
{
    graphic = g;
    g_obj = g->getGraphics();
    for(int i = 0; i < g_obj->size(); i++)
    {
        Graphics *gr = g_obj->at(i);
        if(gr->getSelectToUpDown())
        {
            select = gr;
            index = i;
            break;
        }
    }
}

void DownCommand::Excute()
{
    g_obj->erase(g_obj->begin()+index);
    g_obj->insert(g_obj->begin()+index+1, select);
}

void DownCommand::UnExcute()
{
    g_obj->erase(g_obj->begin()+index+1);
    g_obj->insert(g_obj->begin()+index, select);
}
