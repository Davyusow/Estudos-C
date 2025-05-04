#include "stdio.h"

int main(void) {

  int somaImpar = 0;
  printf("Calculando...\n");

  for (int Contador = 1; Contador <= 1000; Contador += 2) {
    somaImpar += Contador;
  }

  printf("A soma dos números ímpares de 1 à 1000 é: %d\n", somaImpar);
  return 0;
}
