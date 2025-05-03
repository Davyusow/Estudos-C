#include "stdio.h"

int main(void) {
  printf("Digite um valor maior que 0: ");
  int valor;
  scanf("%i", &valor);

  while (valor <= 0) {
    printf("Inválido! Digite um valor maior que 0! ");
    scanf("%i", &valor);
  }

  printf("\nValor lido: %d\n", valor);

  do {
    printf("Digite um valor maior que 0: ");
    scanf("%i", &valor);
  } while (valor <= 0);

  printf("\nValor lido: %d\n", valor);

  return 0;
}
