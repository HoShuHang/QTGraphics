#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <stack>
#include <string>
using namespace std;
class Command
{
public:
    void Undo();
    void Redo();
    virtual void Execute();
    virtual void UnExcute();
private:
    stack<Command *> undo;
    stack<Command *> redo;
};

#endif // COMMAND_H_INCLUDED
