#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *proximo;
} No;

void inserirInicio(No **lista, int num) {
  No *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  } else {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirFim(No **lista, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = NULL;

    // caso seja o primeiro
    if (*lista == NULL) {
      *lista = novo;
    } else {
      aux = *lista;
      while (aux->proximo) {
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
  } else {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirMeio(No **lista, int num, int ant) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    // caso seja o primeiro
    if (*lista == NULL) {
      novo->proximo = NULL;
      *lista = novo;
    } else { // caso não esteja vazia
      aux = *lista;
      while (aux->valor != ant && aux->proximo) {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  } else {
    printf("Erro ao alocar memória!\n");
  }
}

int main(void) { return 0; }
