#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <stack>
#include <string>
using namespace std;
class Command
{
public:
    static void Undo();
    static void Redo();
    void Excute();
    virtual void DoExcute()=0;
    virtual void DoUnExcute()=0;
    static stack<Command *> *undo;
    static stack<Command *> *redo;
};

#endif // COMMAND_H_INCLUDED
