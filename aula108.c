#include "stdio.h"

int main(void) {
  int matriz[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Digite o valor: ");
        scanf(" %i",&matriz[i][j]);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Valor [%i][%i]: %i, ",i,j,matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
