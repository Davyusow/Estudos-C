#include "stdio.h"

void imprimir(int vetor[],int tam){
    if(tam == 0)
        printf("%i, ",vetor[tam]);
    else{
        imprimir(vetor, tam-1);
        printf("%i, ",vetor[tam]);
    }
}

void inverteVetor(int vetor[],int inicio, int fim){
    int temp;
    if(inicio < fim){
        temp = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = temp;
        inverteVetor(vetor,inicio+1,fim-1);
    }
}

int main(void){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10} ;
    imprimir(vetor,9);
    printf("\nVetor invertido: \n");
    inverteVetor(vetor,0,9);
    imprimir(vetor,9);
    return 0;
}
