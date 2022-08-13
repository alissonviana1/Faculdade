#include <QCoreApplication>
#include <bintreeavl.h>
#include <things.h>
#include <bits/stdc++.h>
#include <jogo.h>

using namespace std;

int main()
{
    Jogo jogo;

    int n,l,c,hp,d;
    while(scanf(" %d", &n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            cin>>l>>c>>hp>>d;
            jogo.setDados(i+1,l,c,hp,d);
        }
        int x , y;
        cin>>x>>y;
        jogo.linha = x;
        jogo.coluna = y;
        jogo.qnt = n;
        jogo.quardarDados();
        int a,b;
        while(cin>>a>>b && (a != -1 || b != -1))
        {
            jogo.setPedra(a,b);
        }
        jogo.comando();
        jogo.imprimir();
    }


}
