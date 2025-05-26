#include "stdio.h"

int main(void) {
  int multiplicador;

  printf("Digite um número decimal para saber sua tabuada!: ");
  scanf("%i",&multiplicador);

  for (int i = 0; i <= 10; i++) {
      printf("\n%d X %d = %d",multiplicador,i,multiplicador*i);
  }

  return 0;
}
