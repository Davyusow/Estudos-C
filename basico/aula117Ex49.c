#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void) {
  srand(time(NULL));
  int valores[100];

  for (int i = 0; i < 100;) {
    valores[i] = rand() % 101;
    printf("%3i ", valores[i]);
    if (i % 5 == 0 && i != 0)
      printf("\n");
    i++;
  }

  //for (int j = 1; j <= 100; j++) { //muito ineficiente, bubble sort
  //  for (int i = 0; i < 99; i++) {
  //    if (valores[i] > valores[i + 1]) {
  //      int temp = valores[i];
  //      valores[i] = valores[i + 1];
  //      valores[i + 1] = temp;
  //    }
  //  }
  //}

  int troca;
  do{
    troca = 0;
    for (int i = 0; i < 99; i++) {
      if (valores[i] > valores[i + 1]) {
        int temp = valores[i];
        valores[i] = valores[i + 1];
        valores[i + 1] = temp;
        troca++;
      }
    }
  }while(troca); //quando não hover mais trocas termina a ordenação
  //um pouco mais eficiente

  printf("\nTa ordeanada eles disseram...\n");
  for (int i = 0; i < 100;) {
    printf("%3i ", valores[i]);
    if (i % 5 == 0 && i != 0)
      printf("\n");
    i++;
  }

  return 0;
}