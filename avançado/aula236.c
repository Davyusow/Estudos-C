#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

No* remover(No **fila){
  No *remover = NULL;
  
  if(fila){
    remover = *fila;
    *fila = remover->proximo;
  }else{
    printf("\nFila vazia!");
  }

  return remover;
}

void imprimir(No *fila){
  printf("\n\t-----------Fila-----------\n");
  while(fila){
    printf("%d ", fila->valor);
    fila = fila->proximo;
  }
  printf("\n\t--------Fim da Fila-------\n");
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != true) {
    while (getchar() != '\n')
      printf("%s", mensagem);
  }
  return valorLido;
}


#define SAIR 0
#define INSERIR 1
#define REMOVER 2
#define IMPRIMIR 3


int main(void){

  No *removido, *fila = NULL;
  int opcao;

  do{
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%i",&opcao);
    switch (opcao) {
    case INSERIR:
      inserir(&fila, lerInteiro("Digite um valor: ")); 
    break;
    case REMOVER:
      removido = remover(&fila);
      if(removido)
    break;
    case IMPRIMIR:
      imprimir(fila);
    break;
    case SAIR:
    break;
    default:
      printf("\nOpção inválida!\n");
    break;
    }
  }while(opcao != SAIR);

  return 0;
}