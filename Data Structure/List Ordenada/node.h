#ifndef NODE_H
#define NODE_H
#include "things.h"

using namespace std;

class Node
{
    private:
        Things d;
        Node *next;
        Node *prev;
    public:
        static Node * MontaNode(Things *dat);
        static bool DesmontaNode(Node *p, Things *dat);
        Node * getNext()const{return next;}
        Node * getPrev()const{return prev;}
        void setNext(Node *a){next = a;}
        void setPrev(Node *a){prev = a;}
        Things getD()const{return d;}
        void setD(Things d){this-> d = d;}
};


#endif // NODE_H
