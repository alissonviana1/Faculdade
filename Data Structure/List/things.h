#ifndef THINGS_H
#define THINGS_H
#include <iostream>
using namespace std;

class Things
{
    private:
        int id;
        int key;
    public:
        Things();
        int getId()const{return id;}
        int getKey()const{return key;}
        void setId(int id){this->id = id;}
        void setKey(int key){this->key = key;}
        void ImprimeTudo()const;
};


#endif // THINGS_H
