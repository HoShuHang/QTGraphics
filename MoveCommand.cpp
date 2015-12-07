#include "MoveCommand.h"
#include <iostream>
using namespace std;

MoveCommand::MoveCommand(Graphics *g, int mX, int mY)
{
    moveX = mX;
    moveY = mY;
    graphic = g;
}

void MoveCommand::Excute()
{
    graphic->moveLocation(moveX, moveY);
}

void MoveCommand::UnExcute()
{
    graphic->moveLocation(-moveX, -moveY);
}
