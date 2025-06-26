#include "stdio.h"

#define TRUE 1

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void){
  int A,*B = &A, **C = &B , ***D = &C;

  A = lerInteiro("Digite um valor inteiro: ");

  printf("Valor de A = %i\n", A);
  printf("Valor de B = %i\n", (*B)*2);
  printf("Valor de C = %i\n", (**C)*3);
  printf("Valor de D = %i\n", (***D)*4);
  return 0;
}
