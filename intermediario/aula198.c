#include "stdio.h"
#include "stdlib.h"

int main(void){
  int *x;
  
  //x = malloc(sizeof(int));
  
  x = calloc(1,sizeof(int));  //a diferença dela para o malloc é que o calloc possui um parâmetro a mais
  //o primeiro é a quantidade de elementos alocados, e o segundo o tamanho de cada elemento
  //me parece ser útil em especial com o uso de structs
  
  if(x != NULL){
    printf("Memória alocada com sucesso!\n");
    printf("x: %i\n",*x); //retornou 0 provavelmente por causa do gcc
    *x = 50;
    printf("x: %i\n",*x);
  }
  else
    printf("Erro ao alocar a memória!\n");

  free(x);
  return 0;
}