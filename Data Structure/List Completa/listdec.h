#ifndef LISTDEC_H
#define LISTDEC_H
#include "things.h"
#include "node.h"
using namespace std;

class listDEC
{
private:
    Node * head;
public:
    listDEC();
    bool InsertDEC(Things *DAT);
    bool removeDEC(Things *DAT, int k);
    bool search(Things *DAT, int k);
};

#endif // LISTDEC_H
