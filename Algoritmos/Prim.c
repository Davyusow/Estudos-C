#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SAIR 0
#define PRIM 1

typedef struct No {
  int vertice;
  int chave;
} No;

typedef struct {
  No *dados;
  int *pos;
  int tamanho;
  int maximo;
} MinHeap;

MinHeap *criarMinHeap(int max) {
  MinHeap *heap = malloc(sizeof(MinHeap));
  heap->dados = (No *)malloc(sizeof(No) * max);
  heap->pos = (int *)malloc(sizeof(int) * max);
  heap->tamanho = 0;
  heap->maximo = max;
  return heap;
}

void troca(No *a, No *b) {
  No temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(MinHeap *heap, int indice) {
  int menor = indice;
  int esquerda = 2 * indice + 1;
  int direita = 2 * indice + 2;

  if (esquerda < heap->tamanho &&
      heap->dados[esquerda].chave < heap->dados[menor].chave)
    menor = esquerda;
  if (direita < heap->tamanho &&
      heap->dados[direita].chave < heap->dados[menor].chave)
    menor = direita;

  if (menor != indice) {
    heap->pos[heap->dados[menor].vertice] = indice;
    heap->pos[heap->dados[indice].vertice] = menor;
    troca(&heap->dados[menor], &heap->dados[indice]);
    minHeapify(heap, menor);
  }
}

No extrairMinimo(MinHeap *heap) {
  if (heap->tamanho == 0) {
    No vazio = {-1, -1};
    return vazio;
  }

  No raiz = heap->dados[0];
  No ultimo = heap->dados[heap->tamanho - 1];
  heap->dados[0] = ultimo;

  heap->pos[raiz.vertice] = heap->tamanho - 1;
  heap->pos[ultimo.vertice] = 0;

  heap->tamanho--;
  minHeapify(heap, 0);

  return raiz;
}

void reduzChave(MinHeap *heap, int vertice, int chave) {
  int indice = heap->pos[vertice];
  heap->dados[indice].chave = chave;

  while (indice &&
         heap->dados[indice].chave < heap->dados[(indice - 1) / 2].chave) {
    heap->pos[heap->dados[indice].vertice] = (indice - 1) / 2;
    heap->pos[heap->dados[(indice - 1) / 2].vertice] = indice;
    troca(&heap->dados[indice], &heap->dados[(indice - 1) / 2]);
    indice = (indice - 1) / 2;
  }
}

bool dentroDoHeap(MinHeap *heap, int vertice) {
  return heap->pos[vertice] < heap->tamanho;
}

int **lerGrafo(int *valor) {
  printf("Digite o número de vértices: ");
  scanf("%d", valor);

  int **grafo = (int **)malloc(*valor * sizeof(int *));
  printf("Digite a matriz de conectividade (%i x %i): \n", *valor, *valor);

  for (int i = 0; i < *valor; i++) {
    grafo[i] = (int *)malloc(*valor * sizeof(int));
    for (int j = 0; j < *valor; j++)
      scanf(" %i", &grafo[i][j]);
  }
  return grafo;
}

void prim() {
  int limite;
  int **grafo = lerGrafo(&limite);

  int parente[limite];
  int chave[limite];
  MinHeap *heap = criarMinHeap(limite);

  for (int vertice = 0; vertice < limite; vertice++) {
    parente[vertice] = -1;
    chave[vertice] = INT_MAX;
    heap->dados[vertice].vertice = vertice;
    heap->dados[vertice].chave = INT_MAX;
    heap->pos[vertice] = vertice;
  }

  chave[0] = 0;
  heap->dados[0].chave = 0;
  heap->tamanho = limite;

  while (heap->tamanho > 0) {
    No menorNo = extrairMinimo(heap);
    int u = menorNo.vertice;

    for (int v = 0; v < limite; v++) {
      if (grafo[u][v] && dentroDoHeap(heap, v) && grafo[u][v] < chave[v]) {
        parente[v] = u;
        chave[v] = grafo[u][v];
        reduzChave(heap, v, chave[v]);
      }
    }
  }

  printf("Árvore geradora mínima:\n");
  printf("Aresta \tPeso\n");
  for (int indice = 1; indice < limite; indice++) {
    if (parente[indice] != -1) {
      printf("%d - %d \t%d\n", parente[indice], indice,
             grafo[indice][parente[indice]]);
    }
  }

  for (int i = 0; i < limite; i++) {
    free(grafo[i]);
  }
  free(grafo);
  free(heap->dados);
  free(heap->pos);
  free(heap);
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (!scanf(" %d", &valorLido)) {
    while (getchar() != '\n')
      ;
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void) {

  int opcao;

  do {
    printf("----------------------------------------"
           "\n Grafo com algorítmo de Prim\n"
           "----------------------------------------\n");
    printf(" Digite um número para escolher a opção:  \n"
           " 1 -> Executar algorítmo de Prim\n"
           " 0 -> Para sair\n");
    opcao = lerInteiro("Opção: ");
    switch (opcao) {
    default:
      printf("Opção inválida!");
      break;
    case PRIM:
      prim();
      break;
    case SAIR:
      printf("Até logo!\n");
      break;
    }
  } while (opcao != SAIR);

  return 0;
}
