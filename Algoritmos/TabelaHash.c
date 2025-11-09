#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// contantes lógicos
#define NIL -1

// constantes da tabela Hash
#define VAZIO 0
#define OCUPADO 1
#define REMOVIDO 2

// constantes do menu
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define SAIR 0

// seleção da lista
#define OPEN 0
#define CLOSED 1

typedef struct {
  int chave;
  int estado;
} NoOpen; // open addres

typedef struct No {
  int chave;
  struct No *proximo;
  struct No *anterior;
} NoClosed; // closed addres

typedef struct {
  int tamanho;
  int ocupados;
  NoOpen *dados;
  NoClosed **lista;
  int adress;
} TabelaHash;

int funcaoHash(TabelaHash *tabela, int chave) {
  return chave % tabela->tamanho;
}

void iniciaTabela(TabelaHash *tabela, int tamanho) {
  tabela->tamanho = tamanho;
  tabela->dados = (NoOpen *)malloc(sizeof(NoOpen) * tamanho);
  tabela->adress = OPEN;

  for (int i = 0; i < tamanho; i++) {
    tabela->dados[i].chave = NIL;
    tabela->dados[i].estado = VAZIO;
  }
  tabela->ocupados = 0;
  tabela->lista = NULL;
}

int buscaTabela(TabelaHash *tabela, int chave) {
  if (tabela->adress == OPEN) {
    int indice = funcaoHash(tabela, chave);
    int contador = 0;
    while (contador < tabela->tamanho) {
      if (tabela->dados[indice].estado == VAZIO)
        return NIL;
      if (tabela->dados[indice].estado == OCUPADO &&
          tabela->dados[indice].chave == chave)
        return indice;
      indice = (indice + 1) % tabela->tamanho; // sondagem linear
      contador++;
    }
    return NIL;
  } else if (tabela->adress == CLOSED) { // closed addres com lista ligada
    int indice = funcaoHash(tabela, chave);
    NoClosed *atual = tabela->lista[indice];
    while (atual != NULL) {
      if (atual->chave == chave)
        return indice;
      atual = atual->proximo;
    }
  }
  return NIL;
}

void trocaLista(TabelaHash *tabela) {
  printf("Mudando para closed addressing...\n");
  tabela->lista = (NoClosed **)malloc(sizeof(NoClosed *) * tabela->tamanho);
  for (int i = 0; i < tabela->tamanho; i++) {
    tabela->lista[i] = NULL;
  }
  for (int i = 0; i < tabela->tamanho; i++) {
    if (tabela->dados[i].estado == OCUPADO) {
      int chave = tabela->dados[i].chave;
      int indice = funcaoHash(tabela, chave);

      NoClosed *novo = (NoClosed *)malloc(sizeof(NoClosed));
      novo->chave = chave;
      novo->proximo = tabela->lista[indice];
      novo->anterior = NULL;
      if (tabela->lista[indice] != NULL)
        tabela->lista[indice]->anterior = novo;

      tabela->lista[indice] = novo;
    }
  }
  free(tabela->dados);
  tabela->dados = NULL;
  tabela->adress = CLOSED;
}

int inserirTabela(TabelaHash *tabela, int chave) {
  if (buscaTabela(tabela, chave) != NIL) {
    printf("Elemento já inserido na tabela!\n");
    return false;
  }

  if (tabela->adress == OPEN) {
    int indice = funcaoHash(tabela, chave);
    int contador = 0;

    while (contador < tabela->tamanho) {
      if (tabela->dados[indice].estado != OCUPADO) {
        tabela->dados[indice].chave = chave;
        tabela->dados[indice].estado = OCUPADO;
        tabela->ocupados++;
        return true;
      }
      indice = (indice + 1) % tabela->tamanho;
      contador++;
    }
    printf("Tabela Hash cheia!\n"); // usar closed address hashing
    trocaLista(tabela);
    inserirTabela(tabela,chave);
    return false;
  } else if (tabela->adress == CLOSED) {
    int indice = funcaoHash(tabela, chave);

    NoClosed *novo = (NoClosed *)malloc(sizeof(NoClosed));
    novo->chave = chave;
    novo->proximo = tabela->lista[indice];
    novo->anterior = NULL;

    if (tabela->lista[indice] != NULL)
      tabela->lista[indice]->anterior = novo;

    tabela->lista[indice] = novo;
    tabela->ocupados++;
    return true;
  }
  return false;
}

int excluirTabela(TabelaHash *tabela, int chave) {
  if (tabela->adress == OPEN) {
    int indice = buscaTabela(tabela, chave);
    if (indice == NIL) {
      return false;
    }
    tabela->dados[indice].estado = REMOVIDO;
    tabela->ocupados--;
    return true;
  } else if (tabela->adress == CLOSED) {
    int indice = funcaoHash(tabela, chave);
    NoClosed *atual = tabela->lista[indice];
    NoClosed *anterior = NULL;

    while (atual != NULL) {
      if (atual->chave == chave) {
        if (atual->anterior == NULL) {
          tabela->lista[indice] = atual->proximo;
          if (atual->proximo != NULL) {
            atual->proximo->anterior = NULL;
          }
        } else {
          atual->anterior->proximo = atual->proximo;
          if (atual->proximo != NULL) {
            atual->proximo->anterior = atual->anterior;
          }
        }
        free(atual);
        return true;
      }
      atual = atual->proximo;
    }
    return false;
  }
  return false;
}

void imprimeTabela(TabelaHash *tabela) {
  printf("[ ");

  if (tabela->adress == OPEN) {
    for (int i = 0; i < tabela->tamanho; i++) {
      if (tabela->dados[i].estado == REMOVIDO ||
          tabela->dados[i].estado == VAZIO)
        printf("NIL ");
      else
        printf("%i ", tabela->dados[i].chave);
    }
  } else if (tabela->adress == CLOSED) {
    for (int i = 0; i < tabela->tamanho; i++) {
      NoClosed *atual = tabela->lista[i];
      while (atual != NULL) {
        printf("%i ", atual->chave);
        atual = atual->proximo;
      }
    }
  }
  printf("]\n");
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

int main(void) {

  TabelaHash tabela;
  int opcao, tamanho;

  printf("Primeiramente, insira o tamanho(inteiro maior que 0) desejado para o vetor.\n");

  do {
    tamanho = lerInteiro("Tamanho: ");
  } while (tamanho < 1);

  iniciaTabela(&tabela, tamanho);

  do {
    int tempChave = NIL;
    if(tabela.adress == OPEN){
      printf("---------------------------------------"
           "\nLista Linear Sequencial com Tabela Hash\n"
           "---------------------------------------\n");}

    else if(tabela.adress == CLOSED){
      printf("------------------------------------------"
           "\nLista Duplamente Encadeada com Tabela Hash\n"
           "------------------------------------------\n");}

    printf(" Digite um número para escolher a opção:  \n"
           " 1 ⟶ Para Imprimir o vetor\n"
           " 2 ⟶ Para inserir um valor\n"
           " 3 ⟶ Para buscar um valor\n"
           " 4 ⟶ Para excluir um valor\n"
           " 0 ⟶ Para sair\n");
    opcao = lerInteiro("Opção: ");

    switch (opcao) {
    default:
      system("clear");
      printf("Opção inválida!\n");
      break;
    case VER:
      system("clear");
      printf("Imprimindo...\n");
      imprimeTabela(&tabela);
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      tempChave =
          lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      inserirTabela(&tabela, tempChave);
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      int tempBusca = buscaTabela(&tabela, tempChave);
      if (tempBusca != NIL)
        printf("O valor %i foi encontrado no índice %i.\n", tempChave, tempBusca);
      else
        printf("%i não esta presente no vetor.\n", tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da tabela: ");
      if (excluirTabela(&tabela, tempChave) == true)
        printf("Valor removido com sucesso!\n");
      else
        printf("Valor não existe na tabela!\n");
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
    }

  } while (opcao != SAIR);
  printf("Até logo!");
  free(tabela.dados);
  return 0;
}
