#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define Y 5
#define X 7

int main(void) {
  srand(time(NULL));
  int matriz[Y][X];
  int soma = 0;

  for (int i = 0; i < Y; i++)
    for (int j = 0; j < X; j++)
      matriz[i][j] = rand() % 11;

  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
        printf("%2i ",matriz[i][j]);
        soma += matriz[i][j];
    }
    printf("\n");
  }
  printf("\nA soma dos valores da matriz é: %i",soma);

  return 0;
}