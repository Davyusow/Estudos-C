#include "stdio.h"

int main(void) {
  int vet[10];
  int matriz[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  /* Insere valores até a linha estar cheia
 após isso a inserção continua na próxima coluna */

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Valor [%i][%i]: %i, ",i,j,matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  int matriz2[][3] = {1,2,3,4,5,6};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Valor [%i][%i]: %i, ",i,j,matriz2[i][j]);
    }
    printf("\n");
  }

  return 0;
}
