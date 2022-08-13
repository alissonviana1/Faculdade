#include <QCoreApplication>
#include <things.h>
#include <listord.h>
using namespace std;

int main()
{
    int id,key;
    listord list;
    Things elemento;
    for (int i = 0; i < 5; i++)
    {
        cin>>id>>key;
        elemento.setId(id);
        elemento.setKey(key);
        list.push(&elemento);
    }
    Things aux;
    list.search(&aux, 3);
    aux.ImprimeTudo();

}
