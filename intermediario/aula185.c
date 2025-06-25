#include "stdio.h"

int main(void){

  int *p;
  char *p2;
  float *p3;

  printf("Tamanho: %d\n",sizeof(int));  //4bytes
  printf("Tamanho: %d\n",sizeof(p)); //8bytes
  printf("Tamanho: %d\n",sizeof(p2)); //8bytes
  printf("Tamanho: %d\n",sizeof(p3)); //8bytes
  
  //todos os ponteiros ocupam a mesma quantidade de memória porque eles guardam o endereço
  //de memória de uma variável
  
  return 0;
}