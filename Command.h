#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <stack>
#include <string>
using namespace std;
class Command
{
public:
    virtual void Excute()=0;
    virtual void UnExcute()=0;
};

#endif // COMMAND_H_INCLUDED
