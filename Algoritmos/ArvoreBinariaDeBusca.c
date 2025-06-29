#include "stdlib.h"

#define TRUE 1
#define FALSE 0

typedef struct No{
  int dado;
  struct No *esquerda;
  struct No *direita;
}No;

typedef struct{
  No raiz;
}Arvore;

int busca(Arvore arvore ,int chave){
  if(arvore.raiz.dado == chave){
    return arvore.raiz.dado;
  }else{
    No *temp = &arvore.raiz;
    while(TRUE){
      if(temp->dado > chave){
        temp = temp->direita;
      }else if(temp->dado < chave){
        temp = temp->esquerda;
      }
      else if(temp->dado == chave){
        return chave;
      }
  }
}

int main(void){

  return 0;
}