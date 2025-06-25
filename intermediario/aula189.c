#include "stdio.h"

void imprimir(int vet[], int tam){
  for(int i = 0; i < tam; i++)
    printf("%i ",*vet + i); //aritmética de ponteiros
  //aponta sempre para o pŕoximo elemento, como o vetor é organizada sequencialmente
  //funciona exatamente como se estivesse usando vet[i]
  printf("\n");
}


int main(void){
  int vetor[10] = {0,1,2,3,4,5,6,7,8,9};
  imprimir(vetor, 10);
  
  return 0;
}