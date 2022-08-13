#include "jogo.h"

Jogo::Jogo()
{
    linha = 0;
    coluna = 0;
    qnt = 0;

}

void Jogo::setDados(int jgr, int l, int c, int hp, int d)
{

    Things jogador;
    jogador.jgr = jgr;
    jogador.x = l;
    jogador.y = c;
    jogador.dano = d;
    jogador.id = 1;
    jogador.hp = hp;
    jogador.key = 0;
    lst.push_back(jogador);
    lst2.InsertDEC(&jogador);

}

void Jogo::quardarDados()
{
    while(!lst.empty())
    {
        int pos = (lst.front().x * linha) + lst.front().y;
        Things aux = lst.front();
        aux.key = pos;
        tree.InsertAVL(&aux);
        lst.pop_front();
    }
}

void Jogo::imprimir()
{
    tree.imprimir();
}

void Jogo::setPedra(int l, int c)
{
    int pos = (l*linha)+c;
    Things aux;
    aux.id = 0;
    aux.key = pos;
    tree.InsertAVL(&aux);
}

void Jogo::comando()
{
    char a;
    int dire;
    NodeD *jgr;
    jgr = lst2.head;
    int cont = 0;

    while(cin>>a>>dire && (a != 'F' && dire != 0))
    {
        cont++;
        if(cont == 5)
        {
            jgr = jgr->prev;
            cont = 0;
        }
        if(jgr->d.hp <= 0)
        {
            Things t,r;
            lst2.removeDEC(&t,jgr->d.key);
            tree.RemoveAVL(t.key, &r);
        }
        else
        {
            Things aux;
            if(a == 'M')
            {
                if(jgr->d.hp - 1 > 0)
                {
                    if(dire == 6)
                    {
                        if(jgr->d.y + 1 < coluna)
                        {
                            tree.RemoveAVL(jgr->d.key,&aux);
                            Things aux2;
                            jgr->d.y = aux.y + 1;
                            jgr->d.key = (jgr->d.x * linha) + jgr->d.y;
                            aux2 = jgr->d;
                            aux2.hp = aux2.hp - 1;
                            tree.InsertAVL(&aux2);
                        }
                    }
                    else
                    {
                        if(dire == 2)
                        {
                            if(jgr->d.x + 1 < linha)
                            {
                                tree.RemoveAVL(jgr->d.key, &aux);
                                Things aux2;
                                jgr->d.x =aux.x + 1;
                                jgr->d.key = (jgr->d.x * linha) + jgr->d.y;
                                aux2 = jgr->d;

                                aux2.hp = aux2.hp - 1;
                                std::cout<<aux2.hp<<"\n";
                                    tree.InsertAVL(&aux2);
                            }
                        }
                        else
                        {
                            if(dire == 4)
                            {
                                if(jgr->d.y - 1 >= 0)
                                {
                                    tree.RemoveAVL(jgr->d.key, &aux);
                                    Things aux2;
                                    jgr->d.y = aux.y - 1;
                                    jgr->d.key = (jgr->d.x * linha) + jgr->d.y;
                                    aux2 = jgr->d;
                                    aux2.hp = aux2.hp - 1;
                                        tree.InsertAVL(&aux2);
                                }
                            }
                            else
                            {
                                if(jgr->d.x - 1 >= 0)
                                {
                                    tree.RemoveAVL(jgr->d.key, &aux);
                                    Things aux2;
                                    jgr->d.x = aux.x - 1;
                                    jgr->d.key = (jgr->d.x * linha) + jgr->d.y;
                                    aux2 = jgr->d;
                                    aux2.hp = aux2.hp - 1;
                                        tree.InsertAVL(&aux2);
                                }
                            }
                        }
                    }
                }
                jgr = jgr->prev;
            }
            else
            {
                if(a == 'D')
                {
                    if(jgr->d.hp - 3 > 0)
                    {
                        if(dire == 6)
                        {
                            if(jgr->d.y + 1 < coluna)
                            {

                                Things *aux2;
                                if(tree.searchAVL(((jgr->d.x * linha) + jgr->d.y + 1), aux2))
                                {

                                    aux2->hp = aux2->hp - 3;

                                    if(aux2->id)
                                    {
                                        tree.RemoveAVL((jgr->d.x * linha) + jgr->d.y + 1, &aux);
                                    }

                                }

                            }
                        }
                        else
                        {
                            if(dire == 2)
                            {
                                if(jgr->d.x + 1 < linha)
                                {

                                    Things *aux2;
                                    if(tree.searchAVL(((jgr->d.x+1 * linha) + jgr->d.y), aux2))
                                    {

                                        aux2->hp = aux2->hp - 3;

                                        if(aux2->id)
                                        {
                                            tree.RemoveAVL((jgr->d.x +1 * linha) + jgr->d.y, &aux);
                                        }

                                    }

                                }
                            }
                            else
                            {
                                if(dire == 4)
                                {
                                    if(jgr->d.y - 1 >= 0)
                                    {

                                        Things *aux2;
                                        if(tree.searchAVL(((jgr->d.x * linha) + jgr->d.y - 1), aux2))
                                        {

                                            aux2->hp = aux2->hp - 3;

                                            if(aux2->id)
                                            {
                                                tree.RemoveAVL((jgr->d.x * linha) + jgr->d.y - 1, &aux);
                                            }

                                        }

                                    }
                                }
                                else
                                {
                                    if(jgr->d.x - 1 >= 0)
                                    {

                                        Things *aux2;
                                        if(tree.searchAVL(((jgr->d.x-1 * linha) + jgr->d.y), aux2))
                                        {

                                            aux2->hp = aux2->hp - 3;

                                            if(aux2->id)
                                            {
                                                tree.RemoveAVL((jgr->d.x-1 * linha) + jgr->d.y, &aux);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    jgr = jgr->prev;
                }
                else
                {
                    if(a == 'A')
                    {
                        if(jgr->d.hp - 1 > 0)
                        {
                            if(dire == 6)
                            {
                                int dan = jgr->d.dano;
                                while(jgr->d.y + 1 < coluna)
                                {
                                    Things *aux2;
                                    jgr->d.y = jgr->d.y + 1;
                                    jgr->d.key = (jgr->d.x*linha)+jgr->d.y;
                                    if(tree.searchAVL(jgr->d.key,aux2))
                                    {
                                        if(aux2->id)
                                        {
                                            aux2->hp = aux2->hp - dan;
                                        }

                                    }
                                }
                            }
                            else
                            {
                                if(dire == 2)
                                {

                                    int dan = jgr->d.dano;
                                    while(jgr->d.x + 1 < linha)
                                    {
                                        Things *aux2;
                                        jgr->d.x = jgr->d.x + 1;
                                        jgr->d.key = (jgr->d.x*linha)+jgr->d.y;
                                        if(tree.searchAVL(jgr->d.key,aux2))
                                        {
                                            if(aux2->id)
                                            {
                                                aux2->hp = aux2->hp - dan;
                                            }

                                        }
                                    }
                                }
                                else
                                {
                                    if(dire == 4)
                                    {
                                        int dan = jgr->d.dano;
                                        while(jgr->d.y - 1 >= 0)
                                        {
                                            Things *aux2;
                                            jgr->d.y = jgr->d.y - 1;
                                            jgr->d.key = (jgr->d.x*linha)+jgr->d.y;
                                            if(tree.searchAVL(jgr->d.key,aux2))
                                            {
                                                if(aux2->id)
                                                {
                                                    aux2->hp = aux2->hp - dan;
                                                }

                                            }
                                        }
                                    }
                                    else
                                    {
                                        int dan = jgr->d.dano;
                                        while(jgr->d.x -1  >= 0)
                                        {
                                            Things *aux2;
                                            jgr->d.x = jgr->d.x - 1;
                                            jgr->d.key = (jgr->d.x*linha)+jgr->d.y;
                                            if(tree.searchAVL(jgr->d.key,aux2))
                                            {
                                                if(aux2->id)
                                                {
                                                    aux2->hp = aux2->hp - dan;
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                        jgr = jgr->prev;
                    }
                    else
                    {
                        if(a == 'C')
                        {
                            if(jgr->d.hp - 4 > 0)
                            {
                                if(dire == 6)
                                {
                                    if(jgr->d.y + 1 < coluna)
                                    {

                                        Things *aux5;
                                        setPedra(jgr->d.x, jgr->d.y + 1);
                                        tree.searchAVL(jgr->d.key, aux5);
                                        if(!aux5->id)
                                            aux5->hp = aux5->hp - 4;
                                    }
                                }
                                else
                                {
                                    if(dire == 2)
                                    {
                                        if(jgr->d.x + 1 < linha)
                                        {

                                            Things *aux5;
                                            setPedra(jgr->d.x+1, jgr->d.y);
                                            tree.searchAVL(jgr->d.key, aux5);
                                            if(!aux5->id)
                                                aux5->hp = aux5->hp - 4;
                                        }

                                    }
                                    else
                                    {
                                        if(dire == 4)
                                        {
                                            if(jgr->d.y - 1 >= 0)
                                            {
                                                Things *aux5;
                                                setPedra(jgr->d.x, jgr->d.y-1);
                                                tree.searchAVL(jgr->d.key, aux5);
                                                if(!aux5->id)
                                                    aux5->hp = aux5->hp - 4;
                                            }
                                        }
                                        else
                                        {
                                            if(jgr->d.x - 1 >= 0)
                                            {
                                                Things *aux5;
                                                setPedra(jgr->d.x-1, jgr->d.y);
                                                tree.searchAVL(jgr->d.key, aux5);
                                                if(!aux5->id)
                                                    aux5->hp = aux5->hp - 4;
                                            }
                                        }
                                    }
                                }
                            }
                            jgr = jgr->prev;
                        }
                    }
                }
            }
        }
    }

}
