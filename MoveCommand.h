#ifndef MOVECOMMAND_H_INCLUDED
#define MOVECOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"

class MoveCommand : public Command
{
public:
    MoveCommand(Graphics *g, int mX, int mY);
    void Excute();
    void UnExcute();
private:
    Graphics *graphic;
    int moveX, moveY;
};

#endif // MOVECOMMAND_H_INCLUDED
