#ifndef LIST_H
#define LIST_H
#include "node.h"
#include "things.h"

using namespace std;

class List
{
private:
    Node * head;
public:
    List();
    bool IsEmpty();
    bool push(Things *DAT);
    bool pop(Things *DAT, int k);
    bool search(Things *DAT, int k);
};

#endif // LIST_H
