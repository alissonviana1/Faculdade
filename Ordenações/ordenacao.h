#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Ordenacao
{
long long *vet;
long long *aleatorio;
long long *decrescente;
long long tam;
long long maior;
long long tempo;
long long tamanho_do_heap;
clock_t t;
public:
Ordenacao(long long N)
{
    srand (time(NULL));
    try {
        vet = new long long[N];
        aleatorio = new long long[N];
        decrescente = new long long[N];
        std::cout<<"Vetor criado\n";
        tam = N;
        maior = 0;
        tempo = 3*3600000;
        criacaoVetor();
    } catch (std::bad_alloc& ba)
    {
        std::cout<<"Memória cheia\n";
    }
}

~Ordenacao()
{
    delete[] vet;
    delete[] aleatorio;
    delete[] decrescente;
}
void criacaoVetor()
{

    for (long long i = 0; i < tam; i++)
    {
        aleatorio[i] = vet[i] = rand() % 100  + 1;
    }
}

void vetor()
{
    vetorCrescente();
    vetorDecrescente();
    vetorAleatorio();
}

void insertionSort()
{
    long long chave,j;
    for (long long i = 1; i < tam; i++)
    {
        chave = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > chave)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}

void selectionSort()
{
    int aux;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j< tam; j++)
        {
            if (vet[j] < vet[i])
            {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }

    }
}

void bubbleSort()
{
    int aux;
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = tam - 1; j >= i + 1; j--)
        {

            if (vet[j] < vet[j-1])
            {
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }
}

void MergeSort(int p, int r)
{
    if(p<r)
    {
        int q=p+(r-p)/2;
        MergeSort(p,q);
        MergeSort(q+1,r);
        Merge(p,q,r);
    }
}

void Merge(int p,int q,int r)
{
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    int *L = new int[n1];
    int *R = new int[n2];
    for(i=0;i<n1;i++)
        L[i]=vet[p+i];
    for(j=0;j<n2;j++)
        R[j]=vet[q+j+1];
    i=0;
    j=0;
    k=p;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            vet[k]=L[i];
            i++;
        }
        else
        {
            vet[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        vet[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        vet[k]=R[j];
        j++;
        k++;
    }
}

void trocar(int X,int Y)
{
        int aux;
        aux=vet[X];
        vet[X]=vet[Y];
        vet[Y]=aux;
}

void heapify(int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if (l<n&&vet[l]>vet[largest])
        largest=l;
    if (r<n&&vet[r]>vet[largest])
        largest=r;
    if (largest!=i)
    {
        trocar(i,largest);
        heapify(n,largest);
    }
}

void heapSort(int n) {
for(int i=n/2-1;i>=0;i--)
    heapify(n, i);
for(int i=n-1;i>=0;i--)
{
    trocar(0,i);
    heapify(i,0);
}
}

void Quicksort(int p,int r)
{
        if(p<r)
        {
            int q=Partition(p,r);
            Quicksort(p,q-1);
            Quicksort(q+1,r);
        }
 }

 int Partition(int p,int r)
 {
        unsigned int x=vet[r];
        int i=p-1;
        int j;
        for(j=p;j<=r-1;j++){
            if(vet[j]<=x){
                i++;
                trocar(i,j);
            }
        }
        trocar(i+1,r);
        return i+1;
}

int Randomized_Partition(int p,int r)
{
     int i=rand()%(r-p+1)+p;
     trocar(r,i);
     return Partition(p,r);
}

void Randomized_Quicksort(int p,int r)
{
    if(p<r)
    {
        int q=Randomized_Partition(p,r);
        Randomized_Quicksort(p,q-1);
        Randomized_Quicksort(q+1,r);
    }
}

void vetorCrescente()
{
    std::cout<<"Crescente:";
    for (int i = 0; i < tam; i++)
    {
          std::cout<<" "<<vet[i];
    }
    std::cout<<"\n";
}

void vetorDecrescente()
{
    std::cout<<"Decrescente:";
    for (int i = 0; i < tam; i++)
    {
        decrescente[i] = vet[tam-1-i];
        std::cout<<" "<<decrescente[i];
    }
    std::cout<<"\n";
}

void vetorAleatorio()
{
    std::cout<<"Aleatorio:";
    for (int i = 0; i < tam; i++)
    {
        std::cout<<" "<<aleatorio[i];
    }
    std::cout<<"\n";
}

};

#endif // ORDENACAO_H
