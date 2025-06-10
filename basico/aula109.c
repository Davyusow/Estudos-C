#include "stdio.h"

int main(void) {
  int matriz[3][3];
  int matriz2[3][3] = {1,2,3,4,5,6,7,8,9};
  int matriz3[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Digite o valor: ");
        scanf( "%i",&matriz[i][j]);
        matriz3[i][j] = matriz[i][j] + matriz2[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Valor [%i][%i]: %2i, ",i,j,matriz3[i][j]);
    }
    printf("\n");
  }

  return 0;
}
