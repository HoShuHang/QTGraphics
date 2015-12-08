#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED

#include "Command.h"
#include <stack>
#include <vector>
#include "Graphics.h"
#include "CreateCommand.h"
#include "DeleteCommand.h"
#include "MoveCommand.h"
#include "ComposeCommand.h"

using namespace std;

class CommandManager
{
public:
    CommandManager();
    void Undo();
    void Redo();
    void createCommand(vector<Graphics *> *g_vector, Graphics *g);
    void deleteCommand(vector<Graphics *> *g_vector, vector<int> i);
    void moveCommand(Graphics *g, int mX, int mY);
    void composeCommand(vector<Graphics *> *g_vector, vector<int> i);
    void excute(Command *c);
    bool isUndoEmpty();
    bool isRedoEmpty();
private:
    stack<Command *> undo;
    stack<Command *> redo;
};

#endif // COMMANDMANAGER_H_INCLUDED
