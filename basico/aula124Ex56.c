#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHA 4
#define COLUNA 4
#define LIMITE 11

void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = rand() % LIMITE;
}

int main(void) {
  int matriz[LINHA][COLUNA];
  criaMatriz(matriz);

  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      if (y > x )
        printf("%-2d", matriz[y][x]);
      else
        printf("❑ ");
    }
    printf("\n");
  }
  return 0;
}