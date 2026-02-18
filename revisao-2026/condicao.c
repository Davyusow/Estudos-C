#include "stdbool.h"
#include "stdio.h"

int main(void) {

  short var = 200;

  if (var > 200) {
    printf("Var: %i\n", var);
    var = 250;
  } else if (var < 200) {
    printf("Não é maior que 200\n");
  } else {
    printf("Var é 200\n");
  }

  printf("Var: %i\n", var);

  //
  //

  short dias = 385;
  short dia = dias % 7 + 1; // calcula o dia semana

  switch (dia) {
  case 1:
    printf("Domingo");
    break;
  case 2:
    printf("Segunda");
    break;
  case 3:
    printf("Terça");
  }

  return 0;
}
