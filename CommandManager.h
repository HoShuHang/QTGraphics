#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED

#include "Command.h"
#include <vector>
#include "Graphics.h"
#include "CreateCommand.h"
using namespace std;

class CommandManager
{
public:
    void Undo();
    void Redo();
    void createCommand(vector<Graphics *> *g_vector, Graphics *g);
    bool isUndoEmpty();
    bool isRedoEmpty();
private:
    stack<Command *> undo;
    stack<Command *> redo;
};

#endif // COMMANDMANAGER_H_INCLUDED
