#include "CommandManager.h"
#include <iostream>
using namespace std;

CommandManager::CommandManager()
{
}
void CommandManager::Undo()
{
    if(undo.size() <= 0)
        throw string("can not undo exception");
    Command *c = undo.top();
    undo.pop();
    redo.push(c);
    c->UnExcute();
}

void CommandManager::Redo()
{
    if(redo.size() <= 0)
        throw string("can not redo exception");
    Command *c = redo.top();
    redo.pop();
    undo.push(c);
    c->Excute();
}

void CommandManager::createCommand(vector<Graphics *> *g_vector, Graphics *g)
{
    Command *c = new CreateCommand(g_vector, g);
    excute(c);
}

void CommandManager::deleteCommand(vector<Graphics *> *g_vector, int i)
{
    Command *c = new DeleteCommand(g_vector, i);
    excute(c);
}

void CommandManager::moveCommand(Graphics *g, int mX, int mY)
{
    Command *c = new MoveCommand(g, mX, mY);
    excute(c);
}

void CommandManager::excute(Command *c)
{
    undo.push(c);
    while(!redo.empty())
        redo.pop();
    c->Excute();
}

bool CommandManager::isUndoEmpty()
{
    return !undo.empty();
}

bool CommandManager::isRedoEmpty()
{
    return !redo.empty();
}
