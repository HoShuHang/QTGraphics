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

void CommandManager::deleteCommand(vector<Graphics *> *g_vector, vector<int> i)
{
    Command *c = new DeleteCommand(g_vector, i);
    excute(c);
}

void CommandManager::moveCommand(Graphics *g, int mX, int mY)
{
    Command *c = new MoveCommand(g, mX, mY);
    excute(c);
}

void CommandManager::composeCommand(vector<Graphics *> *g_vector, vector<int> i)
{
    Command *c = new ComposeCommand(g_vector, i);
    excute(c);
}

void CommandManager::decomposeCommand(vector<Graphics *> *g_vector, Graphics *g)
{
    Command *c = new DecomposeCommand(g_vector, g);
    excute(c);
}

void CommandManager::upCommand(Graphics *g)
{
    if(g->canUp())
    {
        Command *c = new UpCommand(g);
        excute(c);
    }
}

void CommandManager::downCommand(Graphics *g)
{
    if(g->canDown())
    {
        Command *c = new DownCommand(g);
        excute(c);
    }
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
void CommandManager::cleanUndoRedo()
{
    while(!undo.empty())
        undo.pop();
    while(!redo.empty())
        redo.pop();
}
