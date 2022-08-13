#include "things.h"

Things::Things():
    id(0),
    key(0)
{
}
void Things::ImprimeTudo()const
{
    cout<<this->getId()<<" "<<this->getKey()<<endl;
}
