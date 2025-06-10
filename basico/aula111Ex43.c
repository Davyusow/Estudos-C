#include "stdio.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

#define TAM 10

int main(void) {
  int vetor[10];
  int resultado[10];

  for (int indice = 0; indice < TAM; indice++) {    //recebe os dados
    printf("%i° ", indice+1);
    vetor[indice] = lerInteiro("valor do vetor: ");
  }

  for (int indice = 0; indice < TAM; indice++)  //eleva ao quadrado para o vetor resultado
    resultado[indice] = vetor[indice] * vetor[indice];

  printf("\tVetor original\n");
  for (int indice = 0; indice < TAM; indice++)
    printf("%i° valor: %i\n", indice+1, vetor[indice]);

  printf("\tVetor dos quadrados\n");
  for (int indice = 0; indice < TAM; indice++)
    printf("%i° valor: %i\n", indice+1, resultado[indice]);

  return 0;
}
