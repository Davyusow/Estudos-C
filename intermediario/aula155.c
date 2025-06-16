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

int fatorial(int num){
    if(num == 0 || num == 1)    //condição do fim
        return 1;
    else
        return num * fatorial(num-1);   //enquanto não for um -> resultado = num * (num-1)! ... até 2 * 1!
    //quando finalmente os resultados serão empilhados
}

int main(void){
    int valor = lerInteiro("Digite um valor para calcular seu fatorial: ");
    int resultado = fatorial(valor);
    printf("\033[32mO resultado de %i! é: %i\033[m\n",valor,resultado);
    return 0;
}
