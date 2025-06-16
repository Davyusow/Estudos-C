#include "stdio.h"
#define TRUE 1

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

int exponencial(int num,int expo){
    if(expo == 1){
        return num;
    }else {
        return num * exponencial(num,expo-1);
    }
}

int main(void){
    int base = lerInteiro("Digite o valor da base: ");
    int expoente = lerInteiro("Digite o valor do expoente: ");
    int resultado = exponencial(base, expoente);
    printf("%i^%i é igual a: %i ",base,expoente,resultado);
    return 0;
}
