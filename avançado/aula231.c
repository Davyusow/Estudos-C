#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void imprimir(No *pilha) {
  printf("\tPILHA\n");
  while (pilha) {
    printf("\t%c\n", pilha->caracter);
    pilha = pilha->proximo;
  }
}

int formaPar(char abre, char fecha) {
  switch (fecha) {

  case ']':
    if (abre == '[')
      return true;
    else
      return false;
    break;

  case '}':
    if (abre == '{')
      return true;
    else
      return false;
    break;

  case ')':
    if (abre == '(')
      return true;
    else
      return false;
    break;
  
  default:
    return true;
    break;
  }

}

int formatador(char x[]) {
  int i = 0;

  No *remover, *pilha = NULL;

  while (x[i] != '\0') {
    if (x[i] == '[' || x[i] == '{' || x[i] == '(') {
      pilha = empilhar(pilha, x[i]);
      imprimir(pilha);
    } else if (x[i] == ']' || x[i] == '}' || x[i] == ')') {
      remover = desempilhar(&pilha);
      if(formaPar(remover->caracter,x[i]) == false){
        printf("\tExpressão mal formada\n");
        return true; //mal formada
      }
      free(remover);
    }
    i++;
  }

  if(pilha){
    printf("\tExpressão mal formada!\n");
    return false;
  }else{
    printf("\tExpressão bem formada!\n");
    return true;
  }
}

int main(void) {
  char exp[50];

  printf("\tDigite uma expressão: ");
  scanf("%49[^\n]",exp);
  printf("\nExpressão: %s\nRetorno: %d\n",exp,formatador(exp));

  return 0;
}