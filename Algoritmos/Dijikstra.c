#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SAIR 0
#define DIJKSTRA 1

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

void dijkstra() {
  int limite, origem;
  int **grafo = lerGrafo(&limite);

  printf("Digite o vértice de origem (0 a %i): ", limite - 1);
  scanf(" %i", &origem);

  int dist[limite];
  MinHeap *heap = criarMinHeap(limite);

  for (int v = 0; v < limite; v++) {
    dist[v] = INT_MAX;
    heap->dados[v].vertice = v;
    heap->dados[v].chave = dist[v];
    heap->pos[v] = v;
  }

  dist[origem] = 0;
  reduzChave(heap, origem, dist[origem]);
  heap->tamanho = limite;

  while (heap->tamanho > 0) {
    No minimo = extrairMinimo(heap);
    int u = minimo.vertice;

    for (int v = 0; v < limite; v++) {
      if (grafo[u][v] && dist[u] != INT_MAX &&
          dist[u] + grafo[u][v] < dist[v]) {
        dist[v] = dist[u] + grafo[u][v];
        reduzChave(heap, v, dist[v]);
      }
    }
  }

  printf("\nCaminhos mais curtos a partir do vértice %d:\n", origem);
  printf("Vértice \tDistância\n");
  for (int i = 0; i < limite; i++) {
    if (dist[i] != INT_MAX) {
      printf("%d \t\t%d\n", i, dist[i]);
    } else {
      printf("%d \t\tInalcançável\n", i);
    }
  }

  for (int i = 0; i < limite; i++)
    free(grafo[i]);
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
           "\n Grafo com algorítmo de Dijkstra\n"
           "----------------------------------------\n");
    printf(" Digite um número para escolher a opção:  \n"
           " 1 -> Executar algorítmo de Dijkstra\n"
           " 0 -> Para sair\n");
    opcao = lerInteiro("Opção: ");
    switch (opcao) {
    default:
      printf("Opção inválida!");
      break;
    case DIJKSTRA:
      dijkstra();
      break;
    case SAIR:
      printf("Até logo!\n");
      break;
    }
  } while (opcao != SAIR);

  return 0;
}
