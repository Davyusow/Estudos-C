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


    //retorna um ponteiro para uma região de memória com
    //o primeiro parâmetro é o vetor, o segundo é o novo tamanho
    //o realloc cria um vetor com o novo tamanho com uma cópia dos dados do vetor anterior
    //indiretamante aumentando o tamanho
  }else
    printf("Erro ao alocar memória");

  free(vet);
  return 0;
}