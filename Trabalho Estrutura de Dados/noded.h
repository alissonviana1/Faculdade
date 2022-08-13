#ifndef NODED_H
#define NODED_H
#include "things.h"

class NodeD
{

    public:
    Things d;
    NodeD *next;
    NodeD *prev;
        static NodeD * MontaNode(Things *dat);
        static bool DesmontaNode(NodeD *p, Things *dat);
        NodeD * getNext()const{return next;}
        NodeD * getPrev()const{return prev;}
        void setNext(NodeD *a){next = a;}
        void setPrev(NodeD *a){prev = a;}
        Things getD()const{return d;}
        void setD(Things d){this-> d = d;}
};


#endif // NODE_H
