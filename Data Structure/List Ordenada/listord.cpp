#include "listord.h"


listord::listord()
{
    head = 0;
}
bool listord::push(Things *DAT)
{
    int k = DAT->getKey();
    Node * aux = Node::MontaNode(DAT);
    if(!aux) return false;
    Node **p = &head;
    while(*p && ((*p)->getD()).getKey() < k)
    {
        p = &((*p)->getNext());
    }
    if(*p && ((*p)->getD()).getKey() == k)
        return false;
    aux->setNext(*p);
    *p = aux;
    return true;
}
bool listord::pop(Things *DAT, int k)
{
    Node **p;
    p = &head;
    while(*p && ((*p)->getD()).getKey() != k)
    {
        p = &((*p)->getNext());
    }
    if(*p)
    {
        Node *aux = *p;
        *p = aux->getNext();
        Node::DesmontaNode(aux,DAT);
        return true;
    }
    return false;
}
bool listord::search(Things *DAT, int k)
{
    Node **p;
    p = &head;
    while(*p && ((*p)->getD()).getKey() != k)
    {
        p = &((*p)->getNext());
    }
    if(((*p)->getD()).getKey() == k)
    {
        *DAT = (*p)->getD();
        return true;
    }
    return false;
}
