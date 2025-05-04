#include "stdbool.h"
#include "stdio.h"

#define PRIMO_LIMITE 2

int lerInteiro() {
  int num;
  printf("Digite um valor inteiro maior que 0: ");
  while (scanf(" %d", &num) != 1) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    printf("Digite um valor inteiro maior que 0: ");
  }
  return num;
}

int main(void) {
  int contador = 0, valor = 0;
  bool isPrimo = true;

  do{
    valor = lerInteiro();
  }while(valor <= 0);

  for (contador = valor - 1; contador > PRIMO_LIMITE; contador--) {
    if (valor % contador == 0) {
      printf("\n%d / %d = %d", valor, contador, valor / contador);
      isPrimo = false;
      break;
    }
  }

  isPrimo ? printf("\n%d é primo!\n", valor) : printf("\n%d não é primo!\n", valor);

  return 0;
}
