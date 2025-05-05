#include "stdio.h"

int main(void) {
  int incremento = 1;
  for (int linhas = 0; linhas < 10; linhas++) {
    for (int contador = 0; contador < incremento; contador++)
      printf("*");
    printf("\n");
    incremento++;
  }

  return 0;
}
