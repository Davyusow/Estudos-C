#include "stdbool.h"
#include "stdio.h"

int main(void) {

  int salario = 1000;
  int dias = 7;

  salario++;

  for (int i = 0; i < dias; i++) { // i = 7, dias = 7, false
    salario *= 2;                  // salario = salario * 2;
  }

  printf("Salário: %i\n", salario);

  salario = 1000;

  while (salario < 1000000) {
    salario *= 2;
  }
  printf("Salário: %i\n", salario);

  do {
    salario *= 2;
  } while (salario < 1000000);
  printf("Salário: %i\n", salario);

  return 0;
}
