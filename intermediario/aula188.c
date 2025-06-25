#include "stdio.h"

void imprimir(int vet[], int tam){
  for(int i = 0; i < tam; i++)
    printf("%i ",vet[i]);
  printf("\n");
}

void teste(int vet[], int tam){
  for(int i = 0; i < tam; i++)
    vet[i] = vet[i] * 2;  //altera os valores, pois o vetor é um ponteiro
  printf("\n");
}

int main(void){
  int vetor[10] = {0,1,2,3,4,5,6,7,8,9};
  imprimir(vetor, 10);
  teste(vetor, 10);
  imprimir(vetor, 10);
  
  return 0;
}