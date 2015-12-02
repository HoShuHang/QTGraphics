#include "Command.h"
void Command::Undo()
{
    if(undo.size() <= 0)
        throw string("can not undo exception");
    Command *c = undo.top();
    undo.pop();
    redo.push(c);
    c->UnExcute();
}
void Command::Redo()
{
    if(redo.size() <= 0)
        throw string("can not redo exception");
    Command *c = redo.top();
    redo.pop();
    undo.push(c);
    c->UnExcute();
}