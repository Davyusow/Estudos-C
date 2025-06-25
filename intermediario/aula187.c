#include "stdio.h"

//passagem de parâmetro por valor
void imprimir(int num){
  printf("%i\n",num);
  num = 80; //não altera o valor original, apenas a cópia criada na função
}

//passagem de parâmetro por referência
void imprimirR(int *num){
  printf("%i\n", *num);
  *num = 80;  //aqui altera o conteúdo apontado por num, alterando o valor da variável no main
}
//é um recurso poderoso mas que deve ser usado com cuidado

int main(void){

  int idade = 35;
  imprimir(idade);
  printf("No main: %i\n",idade);

  imprimirR(&idade);
  printf("No main: %i\n",idade);

  return 0;
}