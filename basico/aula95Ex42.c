#include "stdio.h"
#define SIM 1
#define NAO 2

float lerFloat(char *mensagem) {
  float valorLido;
  printf("%s", mensagem);
  while (scanf(" %f", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}
float lerNota(char *mensagem) {
  float notaLida;
  do {
    notaLida = lerFloat(mensagem);

  } while (notaLida < 0 || notaLida > 10);
  return notaLida;
}

int main(void) {
  float notas[2];
  int opcao = SIM;

  do {
    if (opcao == SIM) {
      notas[0] = lerNota("Insira a 1° nota(0,10): ");
      notas[1] = lerNota("Insira a 2° nota(0,10): ");
      printf("Média semestral: %.1f",(notas[0]+notas[1])/2);
    }
    printf("\nDeseja continuar?\n1 - Sim\n2 - Não\n");
    scanf(" %i", &opcao);
    switch (opcao) {
    default:
        printf("Opção inválida!\n");
    case SIM:
      break;
    case NAO:
      break;
    }
  } while (opcao != NAO);

  return 0;
}
