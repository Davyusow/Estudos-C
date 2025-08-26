#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  char caracter;
  struct No *proximo;
} No;

No *empilhar(No *pilha, char valor) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->caracter = valor;
    novo->proximo = pilha;
    return novo;
  }
  return NULL;
}

No *desempilhar(No **pilha) {
  No *remover = NULL;

  if (*pilha) {
    remover = *pilha;
    *pilha = remover->proximo;
  }
  return remover;
}

void inverterTexto(char x[]) {
  int i = 0;

  No *remover, *pilha = NULL;

  while (x[i] != '\0') {
    if (x[i] != ' ') {
      pilha = empilhar(pilha, x[i]);
    } else {
      while (pilha) {
        remover = desempilhar(&pilha);
        printf("%c", remover->caracter);
        free(remover);
      }
      printf(" ");
    }
    i++;
  }
  while (pilha) {
    remover = desempilhar(&pilha);
    printf("%c", remover->caracter);
    free(remover);
  }
  printf(" ");
}

int main(void) {
  char exp[50] = "ouviram do ipiranga as margens plácidas";
  inverterTexto(exp);
  return 0;
}