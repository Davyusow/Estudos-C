#include "stdio.h"

int main(void) {

  int matriz1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char matriz2[3][4] = {'a', 'b', 'c', 'd', 'e', 'f',
                        'g', 'h', 'i', 'j', 'k', 'l'};

  for (int i = 0; i < 3; i++) {
    printf("%d ", matriz1[0][i]);
  }
  printf("\n");
  for (int i = 0; i < 3; i++) {
    printf("%d ", matriz1[i][0]);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Valor [%i][%i]: %i, ", i, j, matriz1[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Valor [%i][%i]: %i, ", i, j, matriz1[i][j]);
    }
    printf("\n");
  }
printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("Valor [%i][%i]: %c, ", i, j, matriz2[i][j]);
    }
    printf("\n");
  }

  return 0;
}
