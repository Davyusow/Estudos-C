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

int somatorio(int num){
    if(num == 1){
        return 1;
    }else {
        return num + somatorio(num - 1);
    }
}

int main(void){
    int valor = lerInteiro("Deseja fazer um somatório de 1 até qual valor?: ");
    int resultado = somatorio(valor);
    printf("O Resultado de ∑x de 1 até %i é : %i\n",valor,resultado);
    return 0;
}
