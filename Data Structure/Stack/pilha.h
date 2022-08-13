#ifndef PILHA_H
#define PILHA_H
#include <node.h>
#include <things.h>

template<class tipo>
class pilha
{
    private:
        Node *top;
    public:
        pilha();
        bool IsEmpty();
        bool pop(tipo *a);
        bool push(tipo *dat);
};
template<class tipo>
pilha<tipo>::pilha():
    top(0)
{
}

template<class tipo>
bool pilha<tipo>::IsEmpty()
{
    if(top == 0)
    {
        return true;
    }
    return false;
}
template<class tipo>
bool pilha<tipo>::push(tipo *dat)
{
    Node *elemento = Node::MontaNode(dat);
    if(!elemento) return false;

    elemento->setNext(top);
    top = elemento;
    return true;
}
template<class tipo>
bool pilha<tipo>::pop(tipo *a)
{
    if(top == 0) return false;
    Node *elemento;
    elemento = top;
    Node::DesmontaNode(elemento,a);
    top = top->getNext();
    return true;
}

#endif // PILHA_H
