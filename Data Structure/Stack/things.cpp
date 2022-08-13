#include "things.h"

things::things():
    id(0),
    nome("")
{
}

void things::ImprimeTudo()const
{
    cout<<this->getId()<<" "<<this->getNome()<<endl;
}
