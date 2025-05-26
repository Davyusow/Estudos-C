#include "stdio.h"

int main(void) {

  int contador = 0;

  printf("Gerado com for:\n");
  for (int i = 0; i <= 10; i++) {   //bom quando souber o inicio e o limite da repetição
    printf("%d ", i);
  }

  printf("\nGerado com while:\n");
  contador = 0;

  while (contador <= 10) {  //bom quando não souber até quando a repetição irá ocorrer
    printf("%d ", contador++);
  }

  contador = 0;

  do {  //bom quando quiser que a condição seja verificada apenas após a primeira repetição
    printf("\nDigite um valor maior que 0: ");
    scanf("%i", &contador);
  } while (contador <= 0);

  return 0;
}
