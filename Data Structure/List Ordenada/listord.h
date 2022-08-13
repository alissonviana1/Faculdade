#ifndef LISTORD_H
#define LISTORD_H
#include <node.h>
#include <things.h>

class listord
{
private:
    Node *head;
public:
    listord();
    bool push(Things *DAT);
    bool pop(Things *DAT, int k);
    bool search(Things *DAT, int k);
};

#endif // LISTORD_H
