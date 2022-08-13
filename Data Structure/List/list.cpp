#include "list.h"

using namespace std;
List::List()
{
    head = 0;
}
bool List::push(Things *DAT)
{
    Node *p = Node::MontaNode(DAT);
    if(!p) return false;
    p->setNext(head);
    head = p;
    return true;
}
bool List::pop(Things *DAT, int k)
{
    Node *A = 0;
    Node *p = head;
    while (p && (p->getD()).getKey() != k)
    {
       A = p;
       p = p->getNext();
    }
    if(!p) return false;
    if(A) A->setNext(p->getNext());
    else   head = p->getNext();
    Node::DesmontaNode(p,DAT);
    return true;
}
bool List::search(Things *DAT, int k)
{
    Node *p = head;
    while (p && (p->getD()).getKey() != k)
    {
       p = p->getNext();
    }
    if(p)
    {
       *DAT = p->getD();
       return true;
    }
    return false;
}
bool List::IsEmpty()
{
    if(!head) return true;
    return false;
}
