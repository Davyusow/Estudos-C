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

int somatorioVetor(int vetor[],int tam){
    if(tam == 0)
        return 0;
    else
        return vetor[tam - 1] + somatorioVetor(vetor,tam - 1);
}

int main(void){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int resultado = somatorioVetor(vetor, 10);
    printf("O resultado da soma de todos os elementos do vetor é de: %i",resultado);
    return 0;
}
