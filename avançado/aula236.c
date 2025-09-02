#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

void inserir(No **fila, int num){
  No* novo = malloc(sizeof(No));
  No* aux;
  if(novo){
    novo->valor = num;
    novo->proximo = NULL;
    if(*fila == NULL){
      *fila = novo;
    }
    else{
      aux = *fila;
      while(aux->proximo){
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
  }else{
    printf("\nErro ao alocar memória");
  }
}

int main(void){

  return 0;
}