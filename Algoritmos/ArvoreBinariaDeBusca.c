#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

// constantes do menu
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define SAIR 0

typedef struct No {
  int dado;
  struct No *pai;
  struct No *esquerda;
  struct No *direita;
} No;

typedef struct {
  No *raiz;
  int niveis;
} Arvore;

void imprimir(No *no) {
  if (no != NULL) {
    imprimir(no->esquerda);
    printf("%i ", no->dado);
    imprimir(no->direita);
  }
}

No *busca(No *no, int chave) { // percurso em ordem
  No *atual = no;

  while (atual != NULL && atual->dado != chave) {
    if (chave < atual->dado) {
      atual = atual->esquerda;
    } else {
      atual = atual->direita;
    }
  }

  return atual;
}

void inserir(Arvore *arvore, int chave) {
  No *novo = (No *)calloc(1, sizeof(No));
  novo->dado = chave;
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->pai = NULL;

  if (arvore->raiz == NULL) {
    arvore->raiz = novo;
    return;
  }

  No *atual = arvore->raiz;
  No *pai = NULL;

  while (atual != NULL) {
    pai = atual;
    if (chave <= atual->dado) {
      atual = atual->esquerda;
    } else {
      atual = atual->direita;
    }
  }

  novo->pai = pai;

  if (chave <= pai->dado) {
    pai->esquerda = novo;
  } else {
    pai->direita = novo;
  }
}

No *encontrarMinimo(No *no) {
  while (no->esquerda != NULL) {
    no = no->esquerda;
  }

  return no;
}

No *sucessor(No *no) {
  if (no->direita != NULL) {
    return encontrarMinimo(no->direita);
  } else {
    No *pai = no->pai;
    while (pai != NULL && no == pai->direita) {
      no = pai;
      pai = pai->pai;
    }
    return pai;
  }
}

int excluir(Arvore *arvore, int chave) {
  if (arvore->raiz == NULL)
    return false;

  No *atual = arvore->raiz;
  No *pai = NULL;

  while (atual != NULL && atual->dado != chave) {
    pai = atual;
    if (chave < atual->dado)
      atual = atual->esquerda;
    else
      atual = atual->direita;
  }
  if (atual == NULL)
    return false;

  // Caso 1: Nó sem filhos
  if (atual->esquerda == NULL && atual->direita == NULL) {
    if (pai == NULL)
      arvore->raiz = NULL;
    else if (pai->esquerda == atual)
      pai->esquerda = NULL;
    else
      pai->direita = NULL;

    free(atual);
  }
  // Caso 2: Nó com apenas um filho
  else if (atual->esquerda == NULL || atual->direita == NULL) {
    No *filho = (atual->esquerda != NULL) ? atual->esquerda : atual->direita;

    if (filho != NULL) {
      filho->pai = pai;
    }

    if (pai == NULL)
      arvore->raiz = filho;
    else if (pai->esquerda == atual)
      pai->esquerda = filho;
    else
      pai->direita = filho;

    free(atual);
  }
  // Caso 3: Nó com dois filhos
  else {
    No *suc = sucessor(atual);

    if (suc != NULL) {
      int valorSucessor = suc->dado;
      No *paiSuc = suc->pai;
      No *filhoSuc = suc->direita;

      if (filhoSuc != NULL) {
        filhoSuc->pai = paiSuc;
      }

      if (paiSuc != NULL) {
        if (paiSuc->esquerda == suc) {
          paiSuc->esquerda = filhoSuc;
        } else {
          paiSuc->direita = filhoSuc;
        }
      }

      atual->dado = valorSucessor;
      free(suc);
    }
  }

  return true;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != true) {
    while (getchar() != '\n')
      ;
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void) {

  Arvore arvore;
  int opcao, tamanho;
  arvore.raiz = NULL;

  do {
    int tempChave = -1;
    printf("---------------------------------------"
           "\n\tÁrvore Binária de Busca\n"
           "---------------------------------------\n");
    printf(" Digite um número para escolher a opção:  \n"
           " 1 ⟶ Para Imprimir a árvore\n"
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
      printf("[ ");
      imprimir(arvore.raiz);
      printf("]\n");
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      tempChave =
          lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      inserir(&arvore, tempChave);
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      No *tempBusca = busca(arvore.raiz, tempChave);
      if (tempBusca != NULL) {
        printf("O valor %i foi encontrado.\n", tempChave);
        if (tempBusca->pai != NULL)
          printf("O pai de %i é %i\n", tempChave, tempBusca->pai->dado);
        if (tempBusca->esquerda != NULL)
          printf("O valor à esquerda de %i é %i\n", tempChave,
                 tempBusca->esquerda->dado);
        if (tempBusca->direita != NULL)
          printf("O valor à direita de %i é %i\n", tempChave,
                 tempBusca->direita->dado);
      } else
        printf("%i não esta presente no vetor.\n", tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da lista: ");
      tempBusca = busca(arvore.raiz, tempChave);
      if (excluir(&arvore, tempChave))
        printf("%i removido com sucesso!\n", tempChave);
      else
        printf("O valor %i não foi encontrado no vetor.\n", tempChave);
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
    }

  } while (opcao != SAIR);
  printf("Até logo!");
  free(arvore.raiz);
  return 0;
}
