#include <QCoreApplication>
#include <things.h>
#include <pilha.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    pilha<things> p1;
    things elemento,tirar;

    int id;
    string nome;

    for (int i = 0; i < 4; i++)
    {
        cin>>id;
        cin>>nome;
        elemento.setId(id);
        elemento.setNome(nome);
        p1.push(&elemento);
    }

    while(p1.pop(&tirar))
    {
        tirar.ImprimeTudo();
    }
}
