#ifndef THINGS_H
#define THINGS_H
#include <string>
#include <iostream>
using namespace std;
class things
{
    private:
        int id;
        string nome;
    public:
        things();
        int getId()const{return id;}
        string getNome()const{return nome;}
        void setId(int id){this->id = id;}
        void setNome(string nome){this->nome = nome;}
        void ImprimeTudo()const;
};


#endif // THINGS_H
