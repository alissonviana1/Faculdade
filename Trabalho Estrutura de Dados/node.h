#ifndef NODE_H
#define NODE_H
#include <fator.h>

template<class tipo>
class Node
{
public:
    Node(){}
    Node *left;
    Node *right;
    fator fb;
    tipo d;
    static Node * MontaNode(tipo *dat);
    static bool DesmontaNode(Node *p, tipo *dat);
};

template<class tipo>
Node<tipo>* Node<tipo>::MontaNode(tipo *dat)
{
    Node<tipo> * p = new Node<tipo>;
    if (p)
    {
        p->d = *dat;
        p->right = 0;
        p->left = 0;
        p->fb.aux = 0;
    }
    return p;
}
template<class tipo>
bool Node<tipo>::DesmontaNode(Node *p, tipo *dat)
{
    if(p)
    {
        *dat = p->d;
        delete p;
        return true;
    }
    return false;
}
#endif // NODE_H
