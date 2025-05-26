#include "stdio.h"
#define NUM_NOTAS 2

int main(void) {
  float notas[NUM_NOTAS];
  int contador = 0;

  do {
    printf("Digite a %d° nota entre 0 a 10: ", contador + 1);
    scanf(" %f", &notas[contador]);
    if (notas[contador] >= 0 && notas[contador] <= 10)
      contador++;
    else
      printf("Nota inválida!\n");
  } while (contador < NUM_NOTAS);

  printf("Notas:\nNota 1: %.1f\nNota 2: %.1f\n", notas[0], notas[1]);

  return 0;
}
