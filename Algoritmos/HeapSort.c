#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void maxHeapify(int vetor[],int indice,int tamanho){
    int esquerda = 2*indice+1;
    int direita = 2*indice+2;
    int maior;
    if(esquerda < tamanho && vetor[esquerda] > vetor[indice])
        maior = esquerda;
    else
        maior = indice;
    if(direita < tamanho && vetor[direita] > vetor[maior])
        maior = direita;
    if(maior != indice){
        int temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;
        maxHeapify(vetor,maior,tamanho);
    }
}

void construirHeap(int vetor[],int tamanho){
    for(int indice = tamanho/2 -1; indice >= 0 ; indice--){
        maxHeapify(vetor,indice,tamanho);
    }
}

void heapSort(int vetor[],int tamanho){
    construirHeap(vetor,tamanho);
    for(int indice = tamanho-1; indice > 0 ;indice--){
        int temp = vetor[0];
        vetor[0] = vetor[indice];
        vetor[indice] = temp;
        maxHeapify(vetor, 0, indice);
    }
}

void imprimeVetor(int vetor[],int tamanho) { 
  printf("[ ");
  for (int indice = 0; indice < tamanho; indice++) {
      printf("%i ", vetor[indice]);
  }
  printf("]\n");
}

void criaVetor(int vetor[],int tamanho) {    //função utilitária para criar vetores com valores aleatórios
  srand(time(NULL));
  for (int y = 0; y < tamanho; y++)
    vetor[y] = rand() % 11;
}

int main(void){
int tamanho = 10;
int* vetor = malloc(sizeof(int)*tamanho);

criaVetor(vetor, tamanho);
imprimeVetor(vetor, tamanho);
heapSort(vetor, tamanho);
imprimeVetor(vetor, tamanho);

free(vetor);
return 0;
}