#include "stdio.h"

void maiorEMenor(int vet[],int tam, int *maior, int *menor){
  *maior = vet[0], *menor = vet[0];
  for(int i = 0;i < tam;i++){
    if(vet[i] > *maior ){
      *maior = vet[i];
    }
    if(vet[i] < *menor ){
      *menor = vet[i];
    }
  }
}

int main(void){
  int vetor[10] = {1,2,3,4,5,6,7,8,9,0};
  int maior;
  int menor;

  maiorEMenor(vetor, 10, &maior, &menor);

  printf("Maior valor = %i\n",maior);
  printf("Menor valor = %i\n",menor);
  return 0;
}