#include "stdio.h"

int* lerNumeros(int numeros[]) {
  for (int i = 0; i < 2;){
    printf("Digite o %d° número: ",i+1);
    scanf(" %i", &numeros[i++]);
  }
  return numeros;
}

int main(void) {
  int opcao;
  int numeros[2];
  printf("Calculadora");
  do {
    printf("\nDigite uma opção válida\n1 - SOMAR\n2 - SUBTRAIR\n3 - "
           "MULTIPLICAR\n4 - DIVIDIR\n0 - SAIR\nOpção: ");
    scanf(" %i", &opcao);
    switch (opcao) {
    default:
      printf("\nOpção inválida, porfavor tente novamente!");
      break;
    case 0:
      printf("\nSaindo...");
      break;
    case 1:
      lerNumeros(numeros);
      printf("\nA soma entre %d e %d é %d",numeros[0],numeros[1],numeros[0] + numeros[1]);
      break;
    case 2:
      lerNumeros(numeros);
      printf("\nA subtração entre %d e %d é %d",numeros[0],numeros[1],numeros[0] - numeros[1]);
      break;
    case 3:
      lerNumeros(numeros);
      printf("\na multiplicação entre %d e %d é %d",numeros[0],numeros[1],numeros[0] * numeros[1]);
      break;
    case 4:
      lerNumeros(numeros);
      printf("\nA divisão entre %d e %d é %d",numeros[0],numeros[1],numeros[0] / numeros[1]);
      break;
    }
  } while (opcao != 0);
}
