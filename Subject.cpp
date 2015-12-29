#include "Subject.h"

void Subject::Attach(Observer *o)
{
    observers.push_back(o);
}

void Subject::Detach(Observer *o)
{

}

void Subject::Notify()
{
    vector<Observer *>::iterator i;
    for (i=observers.begin(); i != observers.end(); ++i)
        (*i)->Update();
}
