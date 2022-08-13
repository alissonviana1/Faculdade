#include "listdec.h"
#include "things.h"
#include "node.h"

using namespace std;
listDEC::listDEC()
{
    head = 0;
}

bool listDEC::InsertDEC(Things *DAT)
{
    Node *p = Node::MontaNode(DAT);
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

bool listDEC::removeDEC(Things *DAT, int k)
{
    if(!head) return false;
    Node *p = head;
    while(p->getNext() != head && (p->getD()).getKey() != k)
    {
        p = p->getNext();
    }
    if((p->getD()).getKey() == k)
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
        Node::DesmontaNode(p,DAT);
        return true;
    }
    return false;
}
bool listDEC::search(Things *DAT, int k)
{
    Node *p = head;
    while(p->getNext() != head && (p->getD()).getKey() != k)
    {
        p = p->getNext();
    }
    if((p->getD()).getKey() == k)
    {
        *DAT = p->getD();
        return true;
    }
    return false;

}
