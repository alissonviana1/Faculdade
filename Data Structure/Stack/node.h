#ifndef NODE_H
#define NODE_H
#include <things.h>

class Node
{
    private:
        things d;
        Node *next;
    public:
        static Node * MontaNode(things *dat);
        static bool DesmontaNode(Node *p, things *dat);
        Node * getNext()const{return next;}
        void setNext(Node *a){next = a;}
        things getD()const{return d;}
        void setD(things d){this-> d = d;}
};
#endif // NODE_H
