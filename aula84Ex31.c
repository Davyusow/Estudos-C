#include "stdio.h"

int lerInteiro(char *mensagem) {
  int num;
  printf("%s", mensagem);
  while (scanf(" %d", &num) != 1) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    printf("%s", mensagem);
  }
  return num;
}

int main(void) {
  int numero = lerInteiro("Digite o 1° número inteiro: ");
  int multiplicador = lerInteiro("Digite o 2° número inteiro: ");
  printf("%d X %d = ", numero, multiplicador);
  int somador = numero;

  if (multiplicador != 0 || numero != 0) {
    if (multiplicador > 0)
      for (int contador = multiplicador - 1; contador > 0; contador--)
        numero += somador;
    else if (multiplicador < 0)
      for (int contador = multiplicador - 1; contador < 0; contador++)
        numero -= somador;
  } else
    numero = 0;

  printf("%d\n", numero);

  return 0;
}
