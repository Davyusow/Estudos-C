#include "stdio.h"
#include "stdlib.h"

#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define SAIR 0
#define TRUE 1
#define FALSE 0
#define NIL -1

typedef struct No {
  int dado;
  int altura;
  int fatorBalanceamento;
  struct No *pai;
  struct No *esquerda;
  struct No *direita;
} No;

typedef struct {
  No *raiz;
} Arvore;

int alturaNo(No *no) {
  if (no == NULL) {
    return NIL;
  }
  return no->altura;
}

void atualizaAltura(No *no) {
  if (no != NULL) {
    int alturaEsq = alturaNo(no->esquerda);
    int alturaDir = alturaNo(no->direita);
    no->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
  }
}

void atualizaFatorBalanceamento(No *no) {
  if (no != NULL) {
    int alturaDir = alturaNo(no->direita);
    int alturaEsq = alturaNo(no->esquerda);
    no->fatorBalanceamento = alturaDir - alturaEsq;
  }
}

No *rotacaoDireita(No *y) {
  No *x = y->esquerda;
  No *T2 = x->direita;

  x->direita = y;
  y->esquerda = T2;

  if (T2 != NULL)
    T2->pai = y;
  x->pai = y->pai;
  if (y->pai != NULL) {
    if (y->pai->esquerda == y) {
      y->pai->esquerda = x;
    } else {
      y->pai->direita = x;
    }
  }
  y->pai = x;

  atualizaAltura(y);
  atualizaFatorBalanceamento(y);
  atualizaAltura(x);
  atualizaFatorBalanceamento(x);

  return x;
}

No *rotacaoEsquerda(No *x) {
  No *y = x->direita;
  No *T2 = y->esquerda;

  y->esquerda = x;
  x->direita = T2;

  if (T2 != NULL)
    T2->pai = x;
  y->pai = x->pai;
  if (x->pai != NULL) {
    if (x->pai->esquerda == x) {
      x->pai->esquerda = y;
    } else {
      x->pai->direita = y;
    }
  }
  x->pai = y;

  atualizaAltura(x);
  atualizaFatorBalanceamento(x);
  atualizaAltura(y);
  atualizaFatorBalanceamento(y);

  return y;
}

No *rotacaoDuplaEsquerda(No *no) {
  no->esquerda = rotacaoEsquerda(no->esquerda);
  return rotacaoDireita(no);
}

No *rotacaoDuplaDireita(No *no) {
  no->direita = rotacaoDireita(no->direita);
  return rotacaoEsquerda(no);
}

void imprimirFormatado(No *no) {
  if (no == NULL)
    return;

  if (no->esquerda != NULL)
    imprimirFormatado(no->esquerda);
  printf("%d(%d) ", no->dado, no->fatorBalanceamento);
  if (no->direita != NULL)
    imprimirFormatado(no->direita);
}

void imprimir(No *no) {
  if (no != NULL) {
    imprimir(no->esquerda);
    printf("%i (Balanceamento: %i Altura: %i) ", no->dado,
           no->fatorBalanceamento, no->altura);
    imprimir(no->direita);
  }
}

No *busca(Arvore *arvore, int chave) {
  No *temp = arvore->raiz;

  while (temp != NULL) {
    if (temp->dado == chave) {
      return temp;
    } else if (temp->dado > chave) {
      temp = temp->esquerda;
    } else {
      temp = temp->direita;
    }
  }
  return NULL;
}

No *rebalancear(No *no, Arvore *arvore) {
  if (no == NULL)
    return NULL;

  atualizaAltura(no);
  atualizaFatorBalanceamento(no);

  if (no->fatorBalanceamento > 1 || no->fatorBalanceamento < -1) {
    if (no->fatorBalanceamento > 1) {
      No *dir = no->direita;
      if (dir->fatorBalanceamento >= 0) {
        printf("no responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        printf("\nrotacao esquerda.\n");
        no = rotacaoEsquerda(no);
      } else {
        printf("no responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        printf("\nrotacao direita dupla.\n");
        no = rotacaoDuplaDireita(no);
      }
    } else {
      No *esq = no->esquerda;
      if (esq->fatorBalanceamento <= 0) {
        printf("no responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        printf("\nrotacao direita.\n");
        no = rotacaoDireita(no);
      } else {
        printf("no responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        printf("\nrotacao esquerda dupla.\n");
        no = rotacaoDuplaEsquerda(no);
      }
    }

    atualizaAltura(no);
    atualizaFatorBalanceamento(no);
  } else {
    printf("arvore ja balanceada.\n");
  }

  if (no->pai == NULL) {
    arvore->raiz = no;
  }
  return no;
}

void inserirAVL(Arvore *arvore, int chave) {
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = chave;
  novo->altura = 0;
  novo->fatorBalanceamento = 0;
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->pai = NULL;

  if (arvore->raiz == NULL) {
    arvore->raiz = novo;
    printf("Inserido %d. Árvore vazia, %d é a raiz.\n", chave, chave);
    return;
  }

  No *atual = arvore->raiz;
  No *pai = NULL;

  while (atual != NULL) {
    pai = atual;
    if (chave < atual->dado) {
      atual = atual->esquerda;
    } else if (chave > atual->dado) {
      atual = atual->direita;
    } else {
      printf("Valor %d já existe na árvore. Não inserido.\n", chave);
      free(novo);
      return;
    }
  }

  if (chave < pai->dado) {
    pai->esquerda = novo;
  } else {
    pai->direita = novo;
  }
  novo->pai = pai;
  printf("Inserido %d como filho de %d.\n", chave, pai->dado);

  No *temp = pai;
  while (temp != NULL) {
    temp = rebalancear(
        temp, arvore); // rebalancear pode retornar um novo nó se houver rotação
    if (temp != NULL) {
      temp = temp->pai; // Sobe para o pai para continuar verificando
    }
  }
}

No *encontrarMinimo(No *no) {
  while (no->esquerda != NULL) {
    no = no->esquerda;
  }
  return no;
}

No *excluirNo(No *no, int chave, Arvore *arvore) {
  if (no == NULL) {
    return NULL;
  }

  if (chave < no->dado) {
    no->esquerda = excluirNo(no->esquerda, chave, arvore);
  } else if (chave > no->dado) {
    no->direita = excluirNo(no->direita, chave, arvore);
  } else {
    if (no->esquerda == NULL ||
        no->direita == NULL) { // Caso 1: Nó sem filhos ou com apenas um filho
      No *temp = (no->esquerda) ? no->esquerda : no->direita;
      if (temp == NULL) { // Nó sem filhos (é uma folha)
        temp = no;
        no = NULL;
      } else { // Nó com um filho
        temp->pai = no->pai;
        *no = *temp;
      }
      free(temp);
    } else { // Caso 3: Nó com dois filhos
      No *temp = encontrarMinimo(no->direita);
      no->dado = temp->dado;
      no->direita = excluirNo(no->direita, temp->dado, arvore);
    }
  }

  if (no == NULL) {
    return no;
  }

  return rebalancear(no, arvore);
}

int excluirAVL(Arvore *arvore, int chave) {
  No *anteriorRaiz = arvore->raiz;
  arvore->raiz = excluirNo(arvore->raiz, chave, arvore);
  if (anteriorRaiz != NULL && arvore->raiz == NULL) {
    printf("Árvore esvaziada.\n");
    return TRUE;
  } else if (arvore->raiz == anteriorRaiz && busca(arvore, chave) != NULL) {
    printf("Valor %d não encontrado para exclusão.\n", chave);
    return FALSE;
  }
  printf("Valor %d removido com sucesso.\n", chave);
  return TRUE;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n')
      printf("%s", mensagem);
  }
  return valorLido;
}

void liberarArvore(No *no) {
  if (no == NULL)
    return;
  liberarArvore(no->esquerda);
  liberarArvore(no->direita);
  free(no);
}

int main(void) {
  Arvore arvore;
  int opcao, tempChave;
  arvore.raiz = NULL;

  do {
    printf("---------------------------------------"
           "\n\tÁrvore AVL\n"
           "---------------------------------------\n");
    printf(" Digite um número para escolher a opção:  \n"
           " 1 -> Para Imprimir a árvore\n"
           " 2 -> Para inserir um valor\n"
           " 3 -> Para buscar um valor\n"
           " 4 -> Para excluir um valor\n"
           " 0 -> Para sair\n");
    opcao = lerInteiro("Opção: ");

    switch (opcao) {
    default:
      system("clear");
      printf("Opção inválida!\n");
      break;
    case VER:
      system("clear");
      printf("Imprimindo...\n");
      if (arvore.raiz == NULL) {
        printf("Árvore vazia.\n");
      } else {
        printf("[ ");
        imprimirFormatado(arvore.raiz);
        printf("]\n");
      }
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      tempChave =
          lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      inserirAVL(&arvore, tempChave);
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      No *tempBusca = busca(&arvore, tempChave);
      if (tempBusca != NULL) {
        printf("O valor %i foi encontrado.\n", tempChave);
        printf("Fator de Balanceamento: %i, Altura: %i\n",
               tempBusca->fatorBalanceamento, tempBusca->altura);
        if (tempBusca->esquerda != NULL)
          printf("O valor à esquerda de %i é %i\n", tempChave,
                 tempBusca->esquerda->dado);
        if (tempBusca->direita != NULL)
          printf("O valor à direita de %i é %i\n", tempChave,
                 tempBusca->direita->dado);
      } else {
        printf("%i não está presente na árvore.\n", tempChave);
      }
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da árvore: ");
      excluirAVL(&arvore, tempChave);
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
    }
  } while (opcao != SAIR);

  printf("Até logo!\n");
  liberarArvore(arvore.raiz);
  return 0;
}
