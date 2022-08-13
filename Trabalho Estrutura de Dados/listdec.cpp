#include "listdec.h"
#include "noded.h"

ListDEC::ListDEC()
{
    head = 0;
}

bool ListDEC::InsertDEC(Things *DAT)
{
    NodeD *p = NodeD::MontaNode(DAT);
    if(p)
    {
        if(!head)
        {
            head = p;
            p->setNext(p);
            p->setPrev(p);
        }
        else
        {
            p->setNext(head);
            p->setPrev(head->getPrev());
            head->setPrev(p);
            head = p;
        }
        return true;
    }
    return false;
}

bool ListDEC::removeDEC(Things *DAT, int k)
{
    if(!head) return false;
    NodeD *p = head;
    while(p->getNext() != head && (p->getD()).key != k)
    {
        p = p->getNext();
    }
    if((p->getD()).key == k)
    {
        if(p->getNext() == p->getPrev())
        {
            head = 0;
        }
        else
        {
            (p->getNext())->setPrev(p->getPrev());
            (p->getPrev())->setNext(p->getNext());
            if(head == p)
            {
                head = p->getNext();
            }
        }
        NodeD::DesmontaNode(p,DAT);
        return true;
    }
    return false;
}
bool ListDEC::search(Things *DAT, int k)
{
    NodeD *p = head;
    while(p->getNext() != head && (p->getD()).key != k)
    {
        p = p->getNext();
    }
    if((p->getD()).key == k)
    {
        *DAT = p->getD();
        return true;
    }
    return false;

}
