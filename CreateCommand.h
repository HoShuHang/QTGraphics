#ifndef CREATECOMMAND_H_INCLUDED
#define CREATECOMMAND_H_INCLUDED

#include "Command.h"
#include <vector>
#include "Graphics.h"

using namespace std;

class CreateCommand : public Command
{
public:
    CreateCommand(vector<Graphics *> *g_vector, Graphics *g);
    void DoExcute();
    void DoUnExcute();
private:
    vector<Graphics *> *graphics;
    Graphics *graphic;
};

#endif // CREATECOMMAND_H_INCLUDED
