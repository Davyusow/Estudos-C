#include "stdio.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void) {
  int comparador = 1, positivos = 0, negativos = 0;

  while (comparador != 0) {
    comparador = lerInteiro("digite um valor inteiro (0 para parar): ");
    if (comparador > 0)
      positivos++;
    else if (comparador < 0)
      negativos++;
  }
  printf("\nPositivos: %d\nNegativos: %d\n",positivos,negativos);

  return 0;
}
