#ifndef UPCOMMAND_H_INCLUDED
#define UPCOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"
#include <vector>
#include <iostream>
using namespace std;

class UpCommand : public Command
{
public:
    UpCommand(Graphics *g);
    void Excute();
    void UnExcute();
private:
    Graphics *graphic;
    vector<Graphics *> *g_obj;
    Graphics *select;
    int index;
};

#endif // UPCOMMAND_H_INCLUDED
