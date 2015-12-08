#ifndef DECOMPOSECOMMAND_H_INCLUDED
#define DECOMPOSECOMMAND_H_INCLUDED

#include "Command.h"
#include <vector>
#include "Graphics.h"
using namespace std;

class DecomposeCommand : public Command
{
public:
    DecomposeCommand(vector<Graphics *> *g, Graphics *comp);
    void Excute();
    void UnExcute();
private:
    vector<Graphics *> *graphics;
    Graphics *compositeGraphic;
};

#endif // DECOMPOSECOMMAND_H_INCLUDED
