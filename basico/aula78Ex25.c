#include "stdio.h"

int main(void) {
  int limite, soma;

  do {
    printf("Insira um número inteiro maior que 0: ");
    scanf(" %i", &limite);
  } while (limite <= 0);

  printf("Valores: ");

  for (int contador = 1; contador < limite; contador++) {
    soma += contador;
    printf("%d + ", contador);
  }
  soma += limite;
  printf("%d = %d\n", limite, soma);

  return 0;
}
