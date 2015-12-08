#ifndef COMPOSECOMMAND_H_INCLUDED
#define COMPOSECOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"
#include <vector>
#include "CompositeGraphics.h"
using namespace std;

class ComposeCommand : public Command
{
public:
    ComposeCommand(vector<Graphics *> *g, vector<int> i);
    void Excute();
    void UnExcute();
private:
    vector<Graphics *> *graphics, *g_obj;
    vector<int> indexs;
    Graphics *compositeGraphic;
};

#endif // COMPOSECOMMAND_H_INCLUDED
