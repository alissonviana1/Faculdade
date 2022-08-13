#include "bintreeavl.h"


binTreeAvl::binTreeAvl()
{
    root = 0;
}

void binTreeAvl::imprimir()
{
    Node<Things> *p = root;
    impOrder(p);
}

void binTreeAvl::impOrder(Node<Things> *R)
{
    if(R)
    {
        impOrder(R->left);
        if(R->d.hp == 0 && R->d.id != 0)
        {
            std::cout<<"Jogador:"<<R->d.jgr<<" MORTO\n";
        }
        else
        {
            if(R->d.id == 1)
            {
                std::cout<<"Jogador:"<<R->d.jgr<<" ("<<R->d.x<<","<<R->d.y<<")"<<"HP: "<<R->d.hp<<endl;
            }
        }
        impOrder(R->right);
    }
}

bool binTreeAvl::InsertAVL(Things *DAT)
{
   Node<Things> *p = Node<Things>::MontaNode(DAT);

   if(p)
   {
       if(!root)
       {
           root = p;
           return true;
       }
       Node<Things> **R = &root;
       insertAVL(R,p);
       return true;
   }
   return false;

}

bool binTreeAvl::RemoveAVL(int k, Things *DAT)
{
    Node<Things> **R = &root;
    removeAVL(R,k,DAT);
}

bool binTreeAvl::searchAVL(int k, Things *DAT)
{
    Node<Things> *R;
    R = root;
    Node<Things>*p;
    p = search(R,k);
    if(p) *DAT = p->d;
    return p;
}

bool binTreeAvl::insertAVL(Node<Things> **R, Node<Things> *p)
{
    if(!(*R))
    {
        *R = p;
        p->fb.aux = 0;
        return true;
    }
    if(p->d.key < (*R)->d.key)
    {
        if(insertAVL(&(*R)->left, p))
        {
            if((*R)->fb.aux == 0)
            {
                (*R)->fb.aux = -1;
                return true;
            }
            if((*R)->fb.aux == 1)
            {
                (*R)->fb.aux = 0;
                return false;
            }
            if(((*R)->left)->fb.aux == -1)
            {
                RSD(R);
                return false;
            }
            RDD(R);
            return false;
        }
        return false;
    }

    if(insertAVL(&(*R)->right,p))
    {
        if((*R)->fb.aux == 0)
        {
            (*R)->fb.aux = 1;
            return true;
        }
        if((*R)->fb.aux == -1)
        {
            (*R)->fb.aux = 0;
            return false;
        }

        if(((*R)->right)->fb.aux == 1)
        {
            RSE(R);
            return  false;
        }
        RDE(R);
        return false;
    }
    return false;
}

bool binTreeAvl::removeAVL(Node<Things> **R, int k, Things *DAT)
{
    if(!(*R)) return false;
    if(k < ((*R)->d.key))
    {
        if(removeAVL(&(*R)->left, k,DAT))
        {
            if((*R)->fb.aux == -1)
            {
                (*R)->fb.aux = 0;
                return true;
            }
            if((*R)->fb.aux == 0)
            {
                (*R)->fb.aux = 1;
                return false;
            }

            if((*R)->right->fb.aux != -1)
            {
                RSE(R);
                if(((*R)->left)->fb.aux == 0)
                {
                    return true;
                }
                return false;
            }
            RDE(R);
            return true;
        }
        return false;
    }
    if(k > ((*R)->d).key)
    {
        if(removeAVL(&(*R)->right,k,DAT))
        {
            if((*R)->fb.aux == 1)
            {
                (*R)->fb.aux = 0;
                return true;
            }
            if((*R)->fb.aux == 0)
            {
                (*R)->fb.aux = -1;
                return false;
            }

            if(((*R)->left)->fb.aux != 1)
            {
                RSD(R);
                if(((*R)->right)->fb.aux == 0)
                {
                    return true;
                }
                return false;
            }
            RDD(R);
            return true;
        }
        return false;
    }
    Node<Things> *p;
    if(!(*R)->right)
    {
        p = *R;
        *R = p->left;
        Node<Things>::DesmontaNode(p,DAT);
        return true;
    }
    if(!(*R)->left)
    {
        p = *R;
        *R = p->right;
        Node<Things>::DesmontaNode(p,DAT);
        return true;
    }
    p = minimo((*R)->right);
    exchange(p, *R);
    if(removeAVL(&(*R)->right,k,DAT))
    {
        if((*R)->fb.aux == 1)
        {
            (*R)->fb.aux = 0;
            return true;
        }
        if((*R)->fb.aux == 0)
        {
            (*R)->fb.aux = -1;
            return false;
        }
        if(((*R)->left)->fb.aux != 1)
        {
            RSD(R);
            if(((*R)->right)->fb.aux == 0)
            {
                return true;
            }
            return false;
        }
        RDD(R);
        return true;
    }
    return false;
}



void binTreeAvl::RSD(Node<Things> **R)
{
    Node<Things> *a = *R;
    Node<Things> *b = a->left;
    a->left = b->right;
    b->right = a;
    *R = b;
    if(b->fb.aux == -1)
    {
        a->fb.aux = 0;
        b->fb.aux = 0;
    }
    else
    {
        a->fb.aux = -1;
        b->fb.aux = 1;
    }
}

void binTreeAvl::RSE(Node<Things> **R)
{
    Node<Things> *a = *R;
    Node<Things> *b = a->right;
    a->right = b->left;
    b->left = a;
    *R = b;
    if(b->fb.aux == 1)
    {
        a->fb.aux = 0;
        b->fb.aux = 0;
    }
    else
    {
        a->fb.aux = 1;
        b->fb.aux = -1;
    }
}

void binTreeAvl::RDE(Node<Things> **R)
{
    Node<Things> *a = *R;
    Node<Things> *b = a->right;
    Node<Things> *c =b->left;

    b->left = c->right;
    a->right = c->left;
    c->right = b;
    c->left = a;
    *R = c;
    if(c->fb.aux == -1)
    {
        a->fb.aux = 0;
        b->fb.aux = 1;
    }
    else
    {
        if(c->fb.aux == 1)
        {
            a->fb.aux = -1;
            b->fb.aux = 0;
        }
        else
        {
            a->fb.aux = 0;
            b->fb.aux = 0;
        }
    }
    c->fb.aux = 0;
}
void binTreeAvl::RDD(Node<Things> **R)
{
    Node<Things> *a = *R;
    Node<Things> *b = a->left;
    Node<Things> *c =b->right;
    b->right = c->left;
    a->left = c->right;
    c->left = b;
    c->right = a;
    *R = c;
    if(c->fb.aux == -1)
    {
        a->fb.aux = 1;
        b->fb.aux = 0;
    }
    else
    {
        if(c->fb.aux == 1)
        {
            a->fb.aux = 0;
            b->fb.aux = -1;
        }
        else
        {
            a->fb.aux = 0;
            b->fb.aux = 0;
        }
    }
    c->fb.aux = 0;
}

Node<Things> *binTreeAvl::minimo(Node<Things> *R)
{
    while(R && R->left)
    {
        R = R->left;
    }
    return R;
}

void binTreeAvl::exchange(Node<Things> *A, Node<Things> *B)
{
    Things aux = A->d;
    A->d = B->d;
    B->d = aux;
}

Node<Things> *binTreeAvl::search(Node<Things> *R, int k)
{
    if(!R || R->d.key == k)
    {
        return R;
    }
    if(k < R->d.key)
    {
        return search(R->left,k);
    }
    return search(R->right, k);
}
