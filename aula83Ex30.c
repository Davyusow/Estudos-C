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

float lerFloat(char *mensagem) {
  float num;
  printf("%s", mensagem);
  while (scanf(" %f", &num) != 1) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    printf("%s", mensagem);
  }
  return num;
}

int main(void) {

  int totalFuncionarios = lerInteiro("Quantos funcionários existem na sua empresa? ");
  float mediaSalarios = 0;

  for (int i = 0; i < totalFuncionarios; i++) {
    printf("%i° - ", i + 1);    //enumera o funcionário
    mediaSalarios += lerFloat("Digite o Salário do funcionário: R$");
  }

  printf("\nA média salarial dos funcionários é de R$%.2f",mediaSalarios / totalFuncionarios);

  return 0;
}
