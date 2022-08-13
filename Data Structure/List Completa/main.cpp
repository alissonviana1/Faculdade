#include <QCoreApplication>
#include "things.h"
#include <iostream>
#include "listdec.h"

using namespace std;

int main()
{
   int id, key;
   listDEC l1;
   Things elemento;
   for (int i = 0; i < 3; ++i)
   {
      cin>>id>>key;
      elemento.setId(id);
      elemento.setKey(key);
      l1.InsertDEC(&elemento);
   }
   Things aux;
   l1.search(&aux,3);
   aux.ImprimeTudo();

}
