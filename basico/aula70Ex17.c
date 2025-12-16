#include "stdio.h"

int main(void) {
  int multiplicador;

  printf("Digite um número decimal para saber sua tabuada!: ");
  scanf("%i",&multiplicador);

  for (int i = 0; i <= 10; i++) {
      printf("\n%d X %d = %d\a",multiplicador,i,multiplicador*i);
  }
  printf("\nTeste!\n");
  return 0;
}
