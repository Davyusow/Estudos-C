#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHA 3
#define COLUNA 3

void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = rand() % 11;
}

void somaMatriz(int matriz1[LINHA][COLUNA], int matriz2[LINHA][COLUNA], int matrizResultado[LINHA][COLUNA]) {
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matrizResultado[y][x] = matriz1[y][x] + matriz2[y][x];
}

void imprimeMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      printf("%i ", matriz[y][x]);
    }
    printf("\n");
  }
}

int main(void) {

  int matrizA[LINHA][COLUNA], matrizB[LINHA][COLUNA], matrizC[LINHA][COLUNA];

  criaMatriz(matrizA);
  system("sleep 1"); //C é tão rápido que sem isso as duas matrizes ficam iguais
  criaMatriz(matrizB);

  somaMatriz(matrizA, matrizB, matrizC);

  printf("MatrizA: \n");
  imprimeMatriz(matrizA);
  printf("MatrizB: \n");
  imprimeMatriz(matrizB);
  printf("MatrizC: \n");
  imprimeMatriz(matrizC);

  return 0;
}