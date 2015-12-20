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
#include "DecomposeCommand.h"
#include "UpCommand.h"
#include "DownCommand.h"

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
    void decomposeCommand(vector<Graphics *> *g_vector, Graphics *g);
    void upCommand(Graphics *g);
    void downCommand(Graphics *g);
    void excute(Command *c);
    bool isUndoEmpty();
    bool isRedoEmpty();
    void cleanUndoRedo();
private:
    stack<Command *> undo;
    stack<Command *> redo;
};

#endif // COMMANDMANAGER_H_INCLUDED
