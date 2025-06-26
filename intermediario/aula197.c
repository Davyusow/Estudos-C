#include "stdio.h"
#include "stdlib.h"

int main(void){
  int *x;
  
  x = malloc(sizeof(int)); //retorna um ponteiro para a região de memória alocada ou NULL se não conseguir alocar
  //o parâmetro do malloc é o tamanho em bytes que desejamos alocar
  //para isso usaremos sizeof que já retorna esse valor e facilita o uso do malloc
  
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