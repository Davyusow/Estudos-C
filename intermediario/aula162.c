#include "stdio.h"

int maiorDoVetor(int vetor[],int tam,int indice ){
    if(tam == 0)
        return vetor[indice];
    else
        return vetor[tam-1] > vetor[indice] ?
        maiorDoVetor(vetor,tam-1,tam-1) : maiorDoVetor(vetor,tam-1,indice) ;
}

int main(void){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int maior = maiorDoVetor(vetor, 10, 0);
    printf("O maior elemento do vetor é %i",maior);
return 0;
}
