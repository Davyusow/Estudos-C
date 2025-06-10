#include "stdlib.h"
#include "time.h"
#include "stdio.h"

#define LINHA 5
#define COLUNA 5
#define LIMITE 11

void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = rand() % LIMITE;
  system("sleep 1"); //por enquanto vai servir pra garantir que as matrizes sejam diferentes
}

int main(void) {
  srand(time(NULL));
  int matrizA[LINHA][COLUNA];

  criaMatriz(matrizA);

  printf("Diagonal principal:  \n");
  
  for (int y = 0; y < LINHA; y++){
    for (int x = 0; x < COLUNA; x++){
        if( y == x)
            printf("%2d",matrizA[y][x]);
        else
            printf("❑ ");
    }
    printf("\n");
  }

  return 0;
}