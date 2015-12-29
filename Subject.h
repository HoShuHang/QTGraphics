#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

#include "Observer.h"
#include <vector>
using namespace std;

class Subject
{
public:
    void Attach(Observer *o);
    void Detach(Observer *o);
    void Notify();
private:
    vector<Observer *> observers;
};

#endif // SUBJECT_H_INCLUDED
