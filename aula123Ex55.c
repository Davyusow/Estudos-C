#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHA 5
#define COLUNA 4
#define LIMITE 11

void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] =
          rand() %
          LIMITE; // tirei o sleep porque só precisa de uma matriz criada
}

int main(void) {
  int matriz[LINHA][COLUNA], matrizTransposta[COLUNA][LINHA];
  criaMatriz(matriz);

  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matrizTransposta[x][y] = matriz[y][x];

  printf("Matriz original: \n");
  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      printf("%-2i ", matriz[y][x]);
    }
    printf("\n");
  }

  printf("\nMatriz transposta: \n");
  for (int y = 0; y < COLUNA; y++) {
    for (int x = 0; x < LINHA; x++) {
      printf("%-2i ", matrizTransposta[y][x]);
    }
    printf("\n");
  }

  return 0;
}
