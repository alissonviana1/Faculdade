#ifndef JOGO_H
#define JOGO_H
#include <bintreeavl.h>
#include <bits/stdc++.h>
#include <listdec.h>

using namespace std;


class Jogo
{
public:
    Jogo();
    binTreeAvl tree;
    list<Things> lst;
    ListDEC lst2;

    int qnt;
    int linha;
    int coluna;
    void setDados(int jgr, int l, int c, int hp, int d);
    void quardarDados();
    void imprimir();
    void setPedra(int l, int c);
    void comando();

};

#endif // JOGO_H
