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

int fibonnaci(int num){
    if(num == 1)
        return 0;
    else{
        if(num == 2)
            return 1;
        else
            return fibonnaci(num-1) + fibonnaci(num-2);
    }

}

int main(void){
    int valor = lerInteiro("Quantos números da sequência de fibonnaci deseja ver?: ");
    int resultado;
    for(int i = 1;i <= valor;i++){
        resultado = fibonnaci(i);
        printf("%i° = %i, ",i,resultado);
    }


    return 0;
}
