#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    clock_t t;
    long long N = 1;
    bool flag = 0;
    int tam,ord;

    while(N==1)
    {
        system("clear");
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tam);
        Ordenacao vetor(tam);
        std::cout<<"(1) Insertion sort\n(2) Selection sort\n"
              "(3) Bubblesort\n(4) Merge sort\n(5) "
              "heapsort\n(6) Quicksort\n(7) Randomized_quicksort\n(0) Sair\n";
        scanf("%d", &ord);
        t = clock();
        if(ord==1)
            vetor.insertionSort();
        if(ord==2)
            vetor.bubbleSort();
        if(ord==3)
            vetor.selectionSort();
        if(ord==4)
            vetor.MergeSort(0,tam-1);
        if(ord==5)
            vetor.Quicksort(0,tam-1);
        if(ord==6)
            vetor.Randomized_Quicksort(0,tam-1);
        if(ord==7)
            vetor.heapSort(tam);
        std::cout<<"Tempo de execucao da opção ("<<ord<<"): "<<((clock() - t)*1000.0)/CLOCKS_PER_SEC<<std::endl;

        vetor.vetor();

        N = 2;
        while(N!= 1 && N!=0)
        {
            cout<<"Deseja continuar? (1)Sim ou (0)Nao:\n";
            scanf("%d", &N);

        }
    }

}
