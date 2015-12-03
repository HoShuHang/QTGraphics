#include "CreateCommand.h"

CreateCommand::CreateCommand(vector<Graphics *> *g_vector, Graphics *g)
{
    graphics = g_vector;
    graphic = g;
}

void CreateCommand::Excute()
{
    graphics->push_back(graphic);
}

void CreateCommand::UnExcute()
{
    graphics->pop_back();
}
