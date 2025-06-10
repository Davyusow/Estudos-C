#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHA 4
#define COLUNA 4
#define LIMITE 11

// apesar de usar random para criar as matrizes
// a chance de sair um quadrado mágido assim é estupidamente baixa
void criaMatriz(int matriz[LINHA][COLUNA]) {
  srand(time(NULL));
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      matriz[y][x] = rand() % LIMITE;
}

int isQuadradoMagico(int matriz[LINHA][COLUNA]) {
  int somaLinha[LINHA], somaColuna[COLUNA];
  int somaDiagonal1, somaDiagonal2;

  for (int i = 0; i < LINHA; i++)
    somaLinha[i] = 0;
  for (int i = 0; i < COLUNA; i++)
    somaColuna[i] = 0;

  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      somaLinha[y] += matriz[y][x];
    }
    somaDiagonal1 += matriz[y][y];
    somaDiagonal2 += matriz[y][LINHA - 1 - y];
  }

  for (int x = 0; x < COLUNA; x++)
    for (int y = 0; y < LINHA; y++)
      somaColuna[x] += matriz[y][x];

  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      if (somaLinha[y] != somaColuna[x])
        return 0;
    }
  }
  return 1;
}

int main(void) {
  int matriz[LINHA][COLUNA];
  criaMatriz(matriz);

  printf("Matriz: \n");
  for (int y = 0; y < COLUNA; y++) {
    for (int x = 0; x < LINHA; x++) {
      printf("%-2i ", matriz[y][x]);
    }
    printf("\n");
  }
  if (isQuadradoMagico(matriz))
    printf("A matriz é um quadrado mágico!");
  else
    printf("A matriz não é um quadrado mágico!");

  return 0;
}