#ifndef DELETECOMMAND_H_INCLUDED
#define DELETECOMMAND_H_INCLUDED

#include "Command.h"
#include <vector>
#include "Graphics.h"
using namespace std;

class DeleteCommand : public Command
{
public:
    DeleteCommand(vector<Graphics *> *g_vector, vector<int> i);
    void Excute();
    void UnExcute();
private:
    vector<Graphics *> *graphics;
    Graphics *graphic;
    vector<int> indexs;
    vector<Graphics *> *g_obj;
};

#endif // DELETECOMMAND_H_INCLUDED
