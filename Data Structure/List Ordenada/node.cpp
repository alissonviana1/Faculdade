#include "node.h"

Node* Node::MontaNode(Things *dat)
{
    Node * p = new Node;
    if (p)
    {
        p->d = *dat;
        p->next = 0;
        p->prev = 0;
    }
    return p;
}

bool Node::DesmontaNode(Node *p, Things *dat)
{
    if(p)
    {
        *dat = p->d;
        delete p;
        return true;
    }
    return false;
}
