#include "stdio.h"

// estrutura 0

int idade = 21;

int main(void) { // estrutura 1

  int resultado = 2;
  { // esturutra 2
    resultado = resultado * 2;
  }
  printf("%i\n", resultado); // 11

  return 0;
}
