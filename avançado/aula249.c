#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

typedef struct lista
{
  No *inicio;
  int tam;
} Lista;

void criarLista(Lista *lista)
{
  lista->inicio = NULL;
  lista->tam = 0;
}

void inserirInicio(Lista *lista, int num)
{
  No *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirFim(Lista *lista, int num)
{
  No *aux, *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    novo->proximo = NULL;

    // caso seja o primeiro
    if (lista->inicio == NULL)
    {
      lista->inicio = novo;
    }
    else
    {
      aux = lista->inicio;
      while (aux->proximo)
      {
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirMeio(Lista *lista, int num, int ant)
{
  No *aux, *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    // caso seja o primeiro
    if (lista->inicio == NULL)
    {
      novo->proximo = NULL;
      lista->inicio = novo;
    }
    else
    { // caso não esteja vazia
      aux = lista->inicio;
      while (aux->valor != ant && aux->proximo)
      {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserirOrdenado(Lista *lista, int num)
{
  No *aux, *novo = malloc(sizeof(No));

  if (novo)
  {
    novo->valor = num;
    if (lista->inicio == NULL)
    {
      novo->proximo == NULL;
      lista->inicio = novo;
    }
    else if (novo->valor < lista->inicio->valor)
    {
      novo->proximo = lista->inicio;
      lista->inicio = novo;
    }
    else
    {
      aux = lista->inicio;
      while (aux->proximo && novo->valor > aux->proximo->valor)
      {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void imprimir(Lista lista)
{
  No *aux = lista.inicio;
  printf("\nLista de tamanho: %i: \n", lista.tam);
  while (aux)
  {
    printf("%i ", aux->valor);
    aux = aux->proximo;
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
#define IMPRIMIR 5

int main(void)
{

  Lista lista;
  criarLista(&lista);

  int opcao = 0;
  do
  {
    printf("\t0 - Sair\n\t1 - Inserir no início\n\t2 - inserir no meio\n\t3 - "
           "inserir no fim\n\t4 - Inserir Ordenado\n\t5 - Imprimir\n");
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
