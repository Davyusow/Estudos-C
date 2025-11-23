#include "stdarg.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define LER_ARQUIVO 5
#define SAIR 0
#define NIL -1
#define TAMANHO_MEM 4096

typedef struct No {
  int dado;
  int altura;
  int fatorfalse;
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

FILE *arquivoLog = NULL;

void imprimeLog(const char *texto, ...) {
  va_list argumentos;

  va_start(argumentos, texto);
  vprintf(texto, argumentos);
  va_end(argumentos);

  if (arquivoLog) {
    va_start(argumentos, texto);
    vfprintf(arquivoLog, texto, argumentos);
    va_end(argumentos);
  }
}

int alturaArvore(Arvore *arvore) {
  if (arvore == NULL || arvore->raiz == NULL) {
    return NIL;
  }
  return alturaNo(arvore->raiz);
}

void atualizaAltura(No *no) {
  if (no != NULL) {
    int alturaEsq = alturaNo(no->esquerda);
    int alturaDir = alturaNo(no->direita);
    no->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
  }
}

void atualizaFatorfalse(No *no) {
  if (no != NULL) {
    int alturaDir = alturaNo(no->direita);
    int alturaEsq = alturaNo(no->esquerda);
    no->fatorfalse = alturaDir - alturaEsq;
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
  atualizaFatorfalse(y);
  atualizaAltura(x);
  atualizaFatorfalse(x);

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
  atualizaFatorfalse(x);
  atualizaAltura(y);
  atualizaFatorfalse(y);

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
  imprimeLog("%d(%d) ", no->dado, no->fatorfalse);
  if (no->direita != NULL)
    imprimirFormatado(no->direita);
}

void imprimir(No *no) {
  if (no != NULL) {
    imprimir(no->esquerda);
    imprimeLog("%i (false: %i Altura: %i) ", no->dado,
           no->fatorfalse, no->altura);
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
  atualizaFatorfalse(no);

  if (no->fatorfalse > 1 || no->fatorfalse < -1) {
    if (no->fatorfalse > 1) {
      No *dir = no->direita;
      if (dir->fatorfalse >= 0) {
        imprimeLog("nó responsável: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        imprimeLog("\nrotação à esquerda.\n");
        no = rotacaoEsquerda(no);
      } else {
        imprimeLog("nó responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        imprimeLog("\nrotação dupla direita.\n");
        no = rotacaoDuplaDireita(no);
      }
    } else {
      No *esq = no->esquerda;
      if (esq->fatorfalse <= 0) {
        imprimeLog("nó responsavel: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        imprimeLog("\nrotação direita.\n");
        no = rotacaoDireita(no);
      } else {
        imprimeLog("nó responsável: %d\n", no->dado);
        imprimirFormatado(arvore->raiz);
        imprimeLog("\nrotação dupla a esquerda.\n");
        no = rotacaoDuplaEsquerda(no);
      }
    }

    atualizaAltura(no);
    atualizaFatorfalse(no);
  } else {
    imprimeLog("arvore já balanceada.\n");
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
  novo->fatorfalse = 0;
  novo->esquerda = NULL;
  novo->direita = NULL;
  novo->pai = NULL;

  if (arvore->raiz == NULL) {
    arvore->raiz = novo;
    imprimeLog("Inserido %d. Árvore vazia, %d é a raiz.\n", chave, chave);
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
      imprimeLog("Valor %d já existe na árvore. Não inserido.\n", chave);
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
  imprimeLog("Inserido %d como filho de %d.\n", chave, pai->dado);

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
    imprimeLog("Árvore esvaziada.\n");
    return true;
  } else if (arvore->raiz == anteriorRaiz && busca(arvore, chave) != NULL) {
    imprimeLog("Valor %d não encontrado para exclusão.\n", chave);
    return false;
  }
  imprimeLog("Valor %d removido com sucesso.\n", chave);
  return true;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  imprimeLog("%s", mensagem);
  while (scanf(" %d", &valorLido) != true) {
    while (getchar() != '\n')
      imprimeLog("%s", mensagem);
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

void processarArquivo(char *caminhoDoArquivo) {
  FILE *arquivo = fopen(caminhoDoArquivo, "r");
  if (!arquivo) {
    imprimeLog("Arquivo não encontrado");
    return;
  }
  Arvore arvore;
  arvore.raiz = NULL;

  char linha[TAMANHO_MEM];
  while (fgets(linha, sizeof(linha), arquivo)) {
    if (linha[0] == '\n' || linha[0] == '\0') {
      continue;
    }

    liberarArvore(arvore.raiz);
    arvore.raiz = NULL;

    char *elemento = strtok(linha, " \n");
    while (elemento != NULL) {
      int valor = atoi(elemento);
      inserirAVL(&arvore, valor);
      elemento = strtok(NULL, " \n");
    }
    imprimeLog("Resultado do conjunto:\n[");
    imprimirFormatado(arvore.raiz);
    imprimeLog("]\nAltura da árvore: %d\n", alturaArvore(&arvore));
    imprimeLog("\n");
  }
  fclose(arquivo);
}

int main(void) {
  Arvore arvore;
  int opcao, tempChave;
  arvore.raiz = NULL;
  arquivoLog = fopen("resultado.log", "w");

  do {
    imprimeLog("---------------------------------------"
           "\n\tÁrvore AVL\n"
           "---------------------------------------\n");
    imprimeLog(" Digite um número para escolher a opção:  \n"
           " 1 -> Para Imprimir a árvore\n"
           " 2 -> Para inserir um valor\n"
           " 3 -> Para buscar um valor\n"
           " 4 -> Para excluir um valor\n"
           " 5 -> Para ler um arquivo\n"
           " 0 -> Para sair\n");
    opcao = lerInteiro("Opção: ");

    switch (opcao) {
    default:
      system("clear");
      imprimeLog("Opção inválida!\n");
      break;
    case VER:
      system("clear");
      imprimeLog("Imprimindo...\n");
      if (arvore.raiz == NULL) {
        imprimeLog("Árvore vazia.\n");
      } else {
        imprimeLog("[ ");
        imprimirFormatado(arvore.raiz);
        imprimeLog("]\n");
        imprimeLog("Altura da árvore: %d\n", alturaArvore(&arvore));
      }
      break;
    case INSERIR:
      system("clear");
      imprimeLog("Inserindo...\n");
      tempChave =
          lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      inserirAVL(&arvore, tempChave);
      break;
    case BUSCAR:
      system("clear");
      imprimeLog("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      No *tempBusca = busca(&arvore, tempChave);
      if (tempBusca != NULL) {
        imprimeLog("O valor %i foi encontrado.\n", tempChave);
        imprimeLog("Fator de false: %i, Altura: %i\n",
               tempBusca->fatorfalse, tempBusca->altura);
        if (tempBusca->esquerda != NULL)
          imprimeLog("O valor à esquerda de %i é %i\n", tempChave,
                 tempBusca->esquerda->dado);
        if (tempBusca->direita != NULL)
          imprimeLog("O valor à direita de %i é %i\n", tempChave,
                 tempBusca->direita->dado);
      } else {
        imprimeLog("%i não está presente na árvore.\n", tempChave);
      }
      break;
    case EXCLUIR:
      system("clear");
      imprimeLog("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da árvore: ");
      excluirAVL(&arvore, tempChave);
      break;
    case SAIR:
      system("clear");
      imprimeLog("Saindo...\n");
      break;
    case LER_ARQUIVO:
      system("clear");
      imprimeLog("Nome do arquivo:...\n");
      char caminho[256];
      system("ls");
      getchar();
      scanf(" %s",caminho);
      processarArquivo(caminho);
    }
  } while (opcao != SAIR);

  imprimeLog("Até logo!\n");
  liberarArvore(arvore.raiz);
  return 0;
}
