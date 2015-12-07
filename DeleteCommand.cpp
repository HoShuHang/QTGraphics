#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(vector<Graphics *> *g_vector, int i)
{
    graphics = g_vector;
    index = i;
}

void DeleteCommand::Excute()
{
    graphic = graphics->at(index);
    graphics->erase(graphics->begin() + index);
}

void DeleteCommand::UnExcute()
{
    graphics->insert(graphics->begin() + index, graphic);
}
