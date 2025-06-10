#include "stdlib.h"
#include "time.h"
#include <stdio.h>

#define LINHA 5
#define COLUNA 10

int main(void) {
  srand(time(NULL));
  int matriz[LINHA][COLUNA];
  int somaLinha[LINHA], somaColuna[COLUNA];


  for (int y = 0; y < LINHA; y++) {
    for (int x = 0; x < COLUNA; x++) {
      matriz[y][x] = rand() % 11;
      printf("%2i ", matriz[y][x]);
    }
    printf("\n");
  }

  // inicia os vetores
  for (int i = 0; i < LINHA; i++)
    somaLinha[i] = 0;
  for (int i = 0; i < COLUNA; i++)
    somaColuna[i] = 0;

  // faz a soma dos dois vetores
  for (int y = 0; y < LINHA; y++)
    for (int x = 0; x < COLUNA; x++)
      somaLinha[y] += matriz[y][x];

  for (int x = 0; x < COLUNA; x++)
    for (int y = 0; y < LINHA; y++)
      somaColuna[x] = matriz[y][x];

  // imprime os vetores
  printf("Soma Linha = [ ");
  for (int y = 0; y < LINHA; y++)
    printf("%i ", somaLinha[y]);
  printf("]\n");

  printf("Soma Coluna = [ ");
  for (int x = 0; x < COLUNA; x++)
    printf("%i ", somaColuna[x]);
  printf("]\n");

  return 0;
}