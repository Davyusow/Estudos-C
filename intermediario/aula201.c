#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void){
  srand(time(NULL));
  int tam, *vet;

  printf("Digite o tamanho do vetor: ");
  scanf(" %i",&tam);
  vet = malloc(sizeof(int)*tam);


  if(vet != NULL){
    for(int i = 0;i < tam;i++){
      vet[i] = rand()%11;
    }
    for(int i = 0;i < tam;i++){
      printf("%i ",vet[i]);
    }

    printf("\nDigite o novo tamanho do vetor: ");
    scanf(" %i",&tam);
    vet = realloc(vet,tam);

    for(int i = 0;i < tam;i++){
      printf("%i ",vet[i]);
    }

  }else
    printf("Erro ao alocar memória");

  free(vet); //libera a memória pré alocada
  return 0;
}
