#include "stdio.h"

int lerTotalFuncionarios(char *mensagem) {
  int num;
  printf("%s", mensagem);
  while (scanf(" %d", &num) != 1) {
    char temp[256];
    fgets(temp, sizeof(temp), stdin);
    printf("%s", mensagem);
  }
  return num;
}

float lerSalario(char *mensagem) {
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

  int totalFuncionarios = lerTotalFuncionarios("Quantos funcionários existem na sua empresa? ");
  float mediaSalarios = 0;

  printf("1° - ");
  mediaSalarios += lerSalario("Digite o Salário do funcionário: R$");
  float maiorSalario = mediaSalarios;
  float menorSalario = mediaSalarios;
  float comparador;

  for (int i = 1; i < totalFuncionarios; i++) {
    printf("%i° - ", i + 1);    //enumera o funcionário
    comparador = lerSalario("Digite o Salário do funcionário: R$");
    mediaSalarios+=comparador;

    if(comparador < menorSalario)
        menorSalario = comparador;
    if(comparador > maiorSalario)
        maiorSalario = comparador;
  }

  printf("\nA média salarial dos funcionários é de R$%.2f",mediaSalarios / totalFuncionarios);
  printf("\nO maior salário foi : R$%.2f",maiorSalario);
  printf("\nO menor salário foi : R$%.2f\n",menorSalario);

  return 0;
}
