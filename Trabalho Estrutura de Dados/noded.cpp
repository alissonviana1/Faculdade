#include "noded.h"

NodeD* NodeD::MontaNode(Things *dat)
{
    NodeD * p = new NodeD;
    if (p)
    {
        p->d = *dat;
        p->next = 0;
        p->prev = 0;
    }
    return p;
}

bool NodeD::DesmontaNode(NodeD *p, Things *dat)
{
    if(p)
    {
        *dat = p->d;
        delete p;
        return true;
    }
    return false;
}
