#include "stdio.h"

int main(void){
  int num = 10;
  int *p; //cria um ponteiro

  p = &num;  //p -> num, p agora aponta para num
  //ponteiro só armazena endereços de memória

  printf("Valor de num: %i", num);
  printf("\nEndereço de num: %p\n",&num); //%p imprime o ponteiro(endereço) da variável
  printf("Valor de p: %p", p); //imprime o endereço que p está apontando
  printf("\nValor apontado por p: %i\n", *p); //imprime o valor de p
  // o * é usado para declarar o ponteiro e para pegar o valor apontado 
  // é possível criar ponteiros para qualquer tipo
  //char,float,long,double e até struct, qualquer um pode ter um ponteiro

  char letra = 'f';
  char *pc = &letra; 

  return 0;
}