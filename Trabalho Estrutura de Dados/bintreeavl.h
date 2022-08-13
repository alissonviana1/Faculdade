#ifndef BINTREEAVL_H
#define BINTREEAVL_H
#include<node.h>
#include <things.h>
#include <bits/stdc++.h>
using namespace std;

class binTreeAvl
{
private:
    Node<Things> *root;
    static bool insertAVL(Node<Things> ** R, Node<Things> *p);
    static bool removeAVL(Node<Things> **R, int k,Things *DAT);
    static void RSD(Node<Things> **R);
    static void RSE(Node<Things> **R);
    static void RDD(Node<Things> **R);
    static void RDE(Node <Things>**R);
    static Node<Things> *minimo(Node<Things> *R);
    static void exchange(Node<Things> *A, Node<Things> *B);
    static Node<Things> *search(Node<Things> *R, int k);
public:
    binTreeAvl();
    void imprimir();
    void impOrder(Node<Things> *R);
    bool InsertAVL(Things *DAT);
    bool RemoveAVL(int k, Things *DAT);
    bool searchAVL(int k, Things *DAT);



};

#endif // BINTREEAVL_H
