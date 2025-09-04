#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *proximo;
} No;

typedef struct fila {
  No *primeiro;
  No *ultimo;
  int tam;
} Fila;

void criarFila(Fila *fila) {
  fila->primeiro = NULL;
  fila->ultimo = NULL;
  fila->tam = 0;
}

void inserirComPrioridade(Fila *fila, int num) {
  No *aux, *novo = malloc(sizeof(No));
  if (novo) {
    novo->valor = num;
    novo->proximo = NULL;
    if (fila->primeiro == NULL) {
      fila->primeiro = novo;
      fila->ultimo = novo;
    } else { // é prioridade?
      if (num > 59) {
        if (fila->primeiro->valor < 60) {
          novo->proximo = fila->primeiro;
          fila->primeiro = novo;
          fila->tam++;
        } else {
          aux = fila->primeiro;
          while (aux->proximo && aux->proximo->valor > 59) {
            aux = aux->proximo;
          }
          novo->proximo = aux->proximo;
          aux->proximo = novo;
        }
      } else {
        fila->ultimo->proximo = novo;
        fila->ultimo = novo;
      }
    }
    fila->tam++;
  }
}

No *remover(Fila *fila) {
  No *remover = NULL;

  if (fila->primeiro) {
    remover = fila->primeiro;
    fila->primeiro = remover->proximo;
    fila->tam--;
  } else {
    printf("\nFila vazia!");
  }

  return remover;
}

void imprimir(Fila *fila) {
  No *aux = fila->primeiro;

  printf("\n\t-----------Fila-----------\n");
  while (aux) {
    printf("%d ", aux->valor);
    aux = aux->proximo;
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

int main(void) {

  No *removido;
  Fila fila;
  criarFila(&fila);
  int opcao;

  do {
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%i", &opcao);
    switch (opcao) {
    case INSERIR:
      inserirComPrioridade(&fila, lerInteiro("Digite um valor: "));
      break;
    case REMOVER:
      removido = remover(&fila);
      if (removido)
        break;
    case IMPRIMIR:
      imprimir(&fila);
      break;
    case SAIR:
      break;
    default:
      printf("\nOpção inválida!\n");
      break;
    }
  } while (opcao != SAIR);

  return 0;
}
