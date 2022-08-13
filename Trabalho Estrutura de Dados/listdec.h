#ifndef LISTDEC_H
#define LISTDEC_H
#include "things.h"
#include <noded.h>

class ListDEC
{
private:

public:
    ListDEC();
    NodeD * head;
    bool InsertDEC(Things *DAT);
    bool removeDEC(Things *DAT, int k);
    bool search(Things *DAT, int k);
};

#endif // LISTDEC_H
