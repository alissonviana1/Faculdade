#include <QCoreApplication>
#include "things.h"
#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    List l1;
    int id,key;
    Things elemento;
    for(int i = 0; i < 5; i++)
    {
        cin>>id>>key;
        elemento.setId(id);
        elemento.setKey(key);
        l1.push(&elemento);
    }
    Things aux;
    l1.search(&aux,3);
    aux.ImprimeTudo();



}
