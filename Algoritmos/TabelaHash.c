#include "math.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// contantes lógicos
#define NIL -1

// constantes do menu
#define SAIR 0
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4

// constantes da tabela Hash
typedef enum Estado { VAZIO, OCUPADO, REMOVIDO } Estado;

typedef struct No {
  int chave;
  struct No *proximo;
} No;

typedef struct Bloco {
  int chave;
  Estado estado;
  struct No *transferencia;
} Bloco;

typedef struct {
  int tamanho;
  int ocupados;
  Bloco *dados;
} TabelaHash;

int funcaoHash(TabelaHash *tabela, int chave) {
  return floor(chave % tabela->tamanho);
}

void iniciaTabela(TabelaHash *tabela, int tamanho) {
  tabela->tamanho = tamanho;
  tabela->ocupados = 0;
  tabela->dados = (Bloco *)malloc(sizeof(Bloco) * tamanho);

  if (tabela->dados == NULL) {
    tabela->tamanho = 0;
    return;
  }

  for (int i = 0; i < tamanho; i++) {
    tabela->dados[i].chave = NIL;
    tabela->dados[i].estado = VAZIO;
    tabela->dados[i].transferencia = NULL;
  }
}

int buscaTabela(TabelaHash *tabela, int chave) {
  if (tabela == NULL)
    return false;

  int busca = funcaoHash(tabela, chave);

  for (int i = 0; i < tabela->tamanho; i++) { // busca Open
    int indice = (busca + i) % tabela->tamanho;
    Bloco *bloco = &tabela->dados[indice];

    if (bloco->estado == VAZIO) {
      break;
    }
    if (bloco->estado == OCUPADO && bloco->chave == chave) {
      return true;
    }
  }
  // busca closed
  Bloco *bloco = &tabela->dados[busca];
  No *atual = bloco->transferencia;

  while (atual != NULL) {
    if (atual->chave == chave) {
      return true;
    }
    atual = atual->proximo;
  }
  return false;
}

void inserirTabela(TabelaHash *tabela, int chave) {
  if (tabela == NULL || tabela->dados == NULL)
    return;

  // inserir Open
  if (tabela->ocupados < tabela->tamanho) {
    int busca = funcaoHash(tabela, chave);

    for (int i = 0; i < tabela->tamanho; i++) {
      int indice = (busca + i) % tabela->tamanho;
      Bloco *bloco = &tabela->dados[indice];

      if (bloco->estado == OCUPADO && bloco->chave == chave) {
        return;
      }

      if (bloco->estado == VAZIO || bloco->estado == REMOVIDO) {
        bloco->chave = chave;
        bloco->estado = OCUPADO;
        tabela->ocupados++;
        return;
      }
    }
  }

  int busca = funcaoHash(tabela, chave);
  Bloco *bloco = &tabela->dados[busca];

  if (bloco->estado == OCUPADO && bloco->chave == chave) {
    return;
  }

  No *atual = bloco->transferencia;
  No *anterior = NULL;

  while (atual != NULL) {
    if (atual->chave == chave) {
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  No *novo = (No *)malloc(sizeof(No));
  if (novo) {
    novo->chave = chave;
    novo->proximo = NULL;
  } else {
    return;
  }

  if (anterior == NULL) {
    bloco->transferencia = novo;
  } else {
    anterior->proximo = novo;
  }
}

int excluirTabela(TabelaHash *tabela, int chave) {
  if (tabela == NULL || tabela->dados == NULL) {
    return false;
  }

  int busca = funcaoHash(tabela, chave);
  // remove open
  for (int i = 0; i < tabela->tamanho; i++) {
    int indice = (busca + i) % tabela->tamanho;
    Bloco *bloco = &tabela->dados[indice];
    if (bloco->estado == VAZIO) {
      break;
    }

    if (bloco->estado == OCUPADO && bloco->chave == chave) {
      bloco->estado = REMOVIDO;
      bloco->chave = NIL;
      tabela->ocupados--;
      return true;
    }
  }

  Bloco *bloco = &tabela->dados[busca];
  No *atual = bloco->transferencia;
  No *anterior = NULL;

  while (atual != NULL) {
    if (atual->chave == chave) {
      if (anterior == NULL) {
        bloco->transferencia = atual->proximo;
      } else {
        anterior->proximo = atual->proximo;
      }
      free(atual);
      return true;
    }
    anterior = atual;
    atual = atual->proximo;
  }
  return false;
}

void imprimeTabela(TabelaHash *tabela) {
  if (tabela == NULL || tabela->dados == NULL) {
    printf("{ }");
    return;
  }

  printf("{ ");

  for (int i = 0; i < tabela->tamanho; i++) {
    Bloco *bloco = &tabela->dados[i];

    if (bloco->estado == OCUPADO) {
      printf(" %d ", bloco->chave);
    } else if (bloco->estado == REMOVIDO) {
      printf(" [X] ");
    } else {
      printf(" [-] ");
    }

    No *temp = tabela->dados[i].transferencia;
    while (temp != NULL) {
      printf("-> %i", temp->chave);
      temp = temp->proximo;
    }
    if (i < tabela->tamanho - 1)
      printf(", ");
  }
  printf("}\n");
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

  printf("Primeiramente, insira o tamanho(inteiro maior que 0) desejado para o "
         "vetor.\n");

  do {
    tamanho = lerInteiro("Tamanho: ");
  } while (tamanho < 1);

  iniciaTabela(&tabela, tamanho);

  do {
    int tempChave = NIL;

    printf("---------------------------------------"
           "\nTabela Hash Open e Closed Adress Hashing\n"
           "---------------------------------------\n");

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
        printf("O valor %i foi encontrado no índice %i.\n", tempChave,
               tempBusca);
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
