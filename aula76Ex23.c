#include "stdio.h"

int main(void) {
  int limite;

  do {
    printf("Digite um valor inteiro maior que 0: ");
    scanf("%i", &limite);
  } while (limite <= 0);

  for (int valor = 1; valor <= limite; valor++) {
    printf("O quadrado de %d é %d\n", valor, valor * valor);
  }

  return 0;
}
