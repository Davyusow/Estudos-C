#include "stdio.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf(" %s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

float lerReal(char *mensagem) {
  float valorLido;
  printf(" %s", mensagem);
  while (scanf(" %f", &valorLido) != 1) {
    while (getchar() != '\n');
    printf(" %s", mensagem);
  }
  return valorLido;
}

int main(void){
    float valores[10];
    int opcao;
    for(int contador = 0;contador<10;contador++){
        printf("%2i - ",contador+1);
        valores[contador] = lerReal("Insira um valor no vetor: ");
    }
    do{
        printf("\n1 - Listar o vetor inicio ao fim\n2 - Listar o vetor na ordem inversa\n0 - sair\n");
        opcao = lerInteiro("Opção: ");
        switch(opcao){
            default:
                printf("Valor inválido!\n");
                break;
            case 1:
                for(int contador = 0;contador < 10;contador++){
                    printf("%.2f ",valores[contador]);
                }
                printf("\n");
                break;
            case 2:
            for(int contador = 9;contador > -1;contador--){
                    printf("%.2f ",valores[contador]);
                }
                printf("\n");
                break;
            case 0:
                printf("\nAté logo!\n");
                break;
        }
    }while(opcao!=0);
    

    return 0;
}
