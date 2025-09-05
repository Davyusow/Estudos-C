#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

void inserirInicio(No **lista, int num)
{
  No *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirFim(No **lista, int num)
{
  No *aux, *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    novo->proximo = NULL;

    // caso seja o primeiro
    if (*lista == NULL)
    {
      *lista = novo;
    }
    else
    {
      aux = *lista;
      while (aux->proximo)
      {
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirMeio(No **lista, int num, int ant)
{
  No *aux, *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    // caso seja o primeiro
    if (*lista == NULL)
    {
      novo->proximo = NULL;
      *lista = novo;
    }
    else
    { // caso não esteja vazia
      aux = *lista;
      while (aux->valor != ant && aux->proximo)
      {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirOrdenado(No **lista, int num)
{ // insertion sort
  No *aux, *novo = malloc(sizeof(No));

  if (novo)
  {
    novo->valor = num;
    if (*lista == NULL)
    {
      novo->proximo = NULL;
      *lista = novo;
    }
    else if (novo->valor < (*lista)->valor)
    {
      novo->proximo = *lista;
      *lista = novo;
    }
    else
    {
      aux = *lista;
      while (aux->proximo && novo->valor > aux->proximo->valor)
      {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  }
  else
  {
    printf("Erro ao alocar memória");
  }
}

No* remover(No **lista, int chave){
  No *aux, *remover = NULL;

  if(*lista){
    if((*lista)->valor == chave){
      remover = *lista;
      *lista = remover->proximo;
    }else{
      aux = *lista;
      while(aux->proximo && aux->proximo->valor != chave){
        aux = aux->proximo;
      }
      if(aux->proximo){
        remover = aux->proximo;
        aux->proximo = remover->proximo;
      }
    }
  }

  return remover;
}

void imprimir(No *no)
{
  printf("\nLista: \n");
  while (no)
  {
    printf("%i ", no->valor);
    no = no->proximo;
  }
  printf("\n");
}

int lerInteiro(char *mensagem)
{
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != true)
  {
    while (getchar() != '\n')
      printf("%s", mensagem);
  }
  return valorLido;
}

#define SAIR 0
#define INSERIR_INICIO 1
#define INSERIR_MEIO 2
#define INSERIR_FIM 3
#define INSERIR_ORDENADO 4
#define REMOVER 5
#define IMPRIMIR 6

int main(void)
{

  No *lista = NULL;

  int opcao = 0;
  do
  {
    printf("\t0 - Sair\n\t1 - Inserir no início\n\t2 - inserir no meio\n\t3 - "
           "inserir no fim\n\t4 - Inserir Ordenado\n\t5 - Remover\n\t6 - Imprimir\n");
    scanf("%i", &opcao);
    switch (opcao)
    {
    case INSERIR_INICIO:
      inserirInicio(&lista, lerInteiro("\nInsira um valor: "));
      break;
    case INSERIR_MEIO:
      inserirMeio(&lista, lerInteiro("\nInsira um valor: "),
                  lerInteiro("\nInsira a chave: "));
      break;
    case INSERIR_FIM:
      inserirFim(&lista, lerInteiro("\nInsira um valor: "));
      break;
    case INSERIR_ORDENADO:
      inserirOrdenado(&lista, lerInteiro("\nInsira um valor: "));
      break;
    case REMOVER:
      remover(&lista, lerInteiro("\nDeseja remover qual valor?:"));
      break;
    case IMPRIMIR:
      imprimir(lista);
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
