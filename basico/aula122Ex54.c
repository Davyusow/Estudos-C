#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHA 7
#define COLUNA 7
#define LIMITE 11

void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = rand() % LIMITE;
  system("sleep 1"); // por enquanto vai servir pra garantir que as matrizes
                     // sejam diferentes
}

int main(void) {
  int parametro = LINHA -1; //já que é uma matriz quadrada os lados são iguais
  int matriz[LINHA][COLUNA];
  criaMatriz(matriz);

  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      if (y + x == parametro)
        printf("%-2d", matriz[y][x]);
      else
        printf("❑ ");
    }
    printf("\n");
  }

  return 0;
}