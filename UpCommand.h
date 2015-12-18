#ifndef UPCOMMAND_H_INCLUDED
#define UPCOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"

class UpCommand : public Command
{
public:
    UpCommand(Graphics *g);
    void Excute();
    void UnExcute();
private:
    Graphics *graphic;
};

#endif // UPCOMMAND_H_INCLUDED
