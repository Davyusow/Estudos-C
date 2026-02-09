#include "stdio.h"
#include <stdlib.h>

int main(void) {

  // Estrutura de código

  int var = 20; // aloca memória para guardar uma variável
  {
    var = 30; // troca o valor da variável com mesmo nome
  }
  printf("%i\n", var); // imprime a variável do ESCOPO DELA
  // 30!

  system("clear");

  int num = 10;

  // if

  if (num >= 10) {
    printf("Num é maior que 10!\n");
  }
  printf("AAAAAAAA\n");

  // else

  if (num > 10) {
    printf("Num é maior ou igual que 10!\n");
  } else {
    printf("Num é menor que 10!\n");
  }
  printf("AAAAAAAA\n");

  // else if

  if (num > 10) {
    printf("Num é maior ou igual que 10!\n");
  } else if (num < 10) {
    printf("Num é menor que 10!\n");
  }
  printf("AAAAAAAA\n");

  // tudo

  if (num > 10) {
    printf("Num é maior ou igual que 10!\n");
  } else if (num < 10) {
    printf("Num é menor que 10!\n");
  } else {
    printf("Num é igual a 10!\n");
  }

  int dia = 123 % 8;

  switch (dia) {
  case 1:
    printf("Domingo\n");
    break;
  case 2:
    printf("Segunda\n");
    break;
  case 3:
    printf("Terça\n");
    break;
  case 4:
    printf("Quarta\n");
    break;
  case 5:
    printf("Quinta\n");
    break;
  case 6:
    printf("Sexta\n");
    break;
  case 7:
    printf("Sábado\n");
    break;
  }

  return 0;
}
