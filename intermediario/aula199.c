#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void){
  srand(time(NULL));
  int tam, *vet;

  printf("Digite o tamanho do vetor: ");
  scanf(" %i",&tam);
  vet = malloc(sizeof(int)*tam); //define o tamanho, bytes de 1 int vezes 4
  //logo é o espaço de 4 bytes

  if(vet != NULL){
    for(int i = 0;i < tam;i++){
      vet[i] = rand()%11;
    }
    for(int i = 0;i < tam;i++){
      printf("%i ",vet[i]);
    }
  }else
    printf("Erro ao alocar memória");

  free(vet);
  return 0;
}