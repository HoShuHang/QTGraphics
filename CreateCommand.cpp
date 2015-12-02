#include "CreateCommand.h"

CreateCommand::CreateCommand(vector<Graphics *> *g_vector, Graphics *g)
{
    graphics = g_vector;
    graphic = g;
}

void CreateCommand::DoExcute()
{
    graphics->push_back(graphic);
}

void CreateCommand::DoUnExcute()
{
    graphics->pop_back();
}
