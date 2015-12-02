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
    void Excute();
    virtual void DoExcute();
    virtual void DoUnExcute();
private:
    stack<Command *> undo;
    stack<Command *> redo;
};

#endif // COMMAND_H_INCLUDED
