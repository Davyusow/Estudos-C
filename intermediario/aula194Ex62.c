#include "stdio.h"

#define TAM 10

int main(void){
  int vetor[TAM] = {0,1,2,3,4,5,6,7,8,9};

  for(int i = 0;i < TAM; i++){
    printf("Endereço do vetor[%i]: %p, ",i,&vetor[i]);
    printf("Valor do vetor[%i]: %i\n",i,vetor[i]);
  }
  return 0;
}