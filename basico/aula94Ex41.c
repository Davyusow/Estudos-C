#include "stdio.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void){
int quebraLinha = lerInteiro("Deseja imprimir quantos númeoros por linha?: ");
int maximo = lerInteiro("Deseja imprimir até que número?: ");

for(int contador = 1;contador < maximo;){
    for(int linhas = 0;linhas < quebraLinha;linhas++){
        printf("%d ",contador++);
        if(contador > maximo){
            break;
        }
    }
    printf("\n");
}

    return 0;
}
