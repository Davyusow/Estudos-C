#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  float valor;
  struct No *proximo;
} No;

No *empilhar(No *pilha, float num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
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

float operacao(float a, float b, char operador){
  switch (operador) {
    case '+':
      return a + b;
    break;
    case '-':
      return a - b;
    break;
    case '*':
      return a * b;
    break;
    case '/':
      return a / b;
    break;
    default:
      return 0.0;
    break;
  }
}

float resolverExpressao(char x[]) { // 51 13 12 * +
 char *operador;
 operador = strtok(x," "); //divide a string toda vez q encontrar " "(espaço) 
 No *num1, *num2, *pilha = NULL;
 float resultado;

 while(operador){
  if(operador[0] == '+' || operador[0] == '-' || operador[0] == '/' || operador[0] == '*'){
    num1 = desempilhar(&pilha);
    num2 = desempilhar(&pilha);
    resultado = operacao(num2->valor, num1->valor, operador[0]);
    pilha = empilhar(pilha, resultado);
    free(num1);
    free(num2);
  }else {
    resultado = strtol(operador, NULL, 10);
    pilha = empilhar(pilha, resultado);
  }
  operador = strtok(NULL," ");
 }
 num1 = desempilhar(&pilha);
 resultado = num1->valor;
 free(num1);
 return resultado;
}

int main(void) {
  char exp[50] = "51 13 12 * +";
  
  printf("Resultado %s : %.2f",exp,resolverExpressao(exp));

  return 0;
}