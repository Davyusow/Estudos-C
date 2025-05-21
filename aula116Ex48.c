#include "stdio.h"
#include "stdlib.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf(" %s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

int* insertionSort(int* vetor,int tam){
    for(int i = 0;i<tam;i++){
        if()

    }
}

int main(void){
    int valores[10];
    int opcao;
    for(int contador = 0;contador<10;contador++){
        printf("%2i - ",contador+1);
        valores[contador] = lerInteiro("Insira um valor no vetor: ");
    }
    do{
        system("clear");
        printf("1 - Listar o vetor ordenado\n2 - Listar o vetor na ordem inversa\n0 - sair\n");
        opcao = lerInteiro("Opção: ");
    }while(opcao!=0);

    return 0;
}
