#ifndef DOWNCOMMAND_H_INCLUDED
#define DOWNCOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"
#include <vector>
#include <iostream>
using namespace std;

class DownCommand : public Command
{
public:
    DownCommand(Graphics *g);
    void Excute();
    void UnExcute();
private:
    Graphics *graphic;
    vector<Graphics *> *g_obj;
    Graphics *select;
    int index;
};

#endif // DOWNCOMMAND_H_INCLUDED
