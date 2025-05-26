#include "stdio.h"

int main(void) {

  for (int linhas = 0; linhas < 10; linhas++) {
    for (int contador = 0; contador < 20; contador++)
      printf("*");
    printf("\n");
  }

  return 0;
}
