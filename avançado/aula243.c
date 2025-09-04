#include <stdlib.h>
#include <stdio.h>

typedef struct no {
  int valor;
  struct no *proximo;
} No;

void inserirInicio(No **lista, int num){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  }else{
    printf("Erro ao alocar memória!\n");
  }
}

int main(void) {

  return 0;
}
