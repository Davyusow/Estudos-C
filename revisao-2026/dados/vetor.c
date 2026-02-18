#include "stdio.h"


#define TAM 5

int main(void) {

  int vetor[TAM] = {1, 2, 3, 4,
                    5}; // 0x120832183, 0x120832184, 0x120832185, 0x120832186...

  printf("Vetor: %i \n", vetor[0]);

  for (int i = 0; i < TAM; i++) {
    printf("%i, ", vetor[i]);
  }
  printf("\n");

  vetor[1] = 100;

  for (int i = 0; i < TAM; i++) {
    printf("%i, ", vetor[i]);
  }
  printf("\n");

  vetor[3] = -1;
  for (int i = 0; i < TAM; i++) {
    if (vetor[i] > 0) {
      printf("%i, ", vetor[i]);
    }
  }
  printf("\n");

  char palavra[] = "Um nome";
  printf("%s\n",palavra);

  return 0;
}
