#include <stdlib.h>

typedef struct No{
   int vertice;
   int chave;
}No;

typedef struct{
    No* dados;
    int *pos;
    int tamanho;
    int maximo;
}MinHeap;

MinHeap *criarMinHeap(int max){
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->dados = (No*)malloc(sizeof(No));
    heap->pos = (int*)malloc(sizeof(int) * max);
    heap->tamanho = 0;
    heap->maximo = max;
    return heap;
}

void troca(No *a, No *b){
    No *temp = a;
    *a = *b;
    *b = *temp;
}

void minHeapify(MinHeap *heap, int indice){
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if(esquerda < heap->tamanho && heap->dados[esquerda].chave < heap->dados[menor].chave)
        menor = esquerda;
    if(direita < heap->tamanho && heap->dados[direita].chave < heap->dados[menor].chave)
        menor = direita;

    if(menor != indice){
        heap->pos[heap->dados[menor].vertice] = indice;
        heap->pos[heap->dados[indice].vertice] = menor;
        troca(&heap->dados[menor],&heap->dados[indice]);
        minHeapify(heap, menor);
    }
}

No minimo(MinHeap *heap){
    if(heap->tamanho == 0){
        No vazio = {-1,-1};
        return vazio;
    }

    No raiz = heap->dados[0];
    No ultimo = heap->dados[heap->tamanho - 1];
    heap->dados[0] = ultimo;

    heap->pos[raiz.vertice] = heap->tamanho - 1 ;
    heap->pos[ultimo.vertice] = 0;

    heap->tamanho--;
    minHeapify(heap,0);

    return raiz;
}

void reduzChave(MinHeap* heap, int vertice, int chave){
    int indice = heap->pos[vertice];
    heap->dados[indice].chave = chave;

    while(indice && heap->dados[indice].chave < heap->dados[(indice - 1) / 2 ].chave){
        heap->pos[heap->dados[indice].vertice] = (indice - 1) / 2;
        heap->pos[heap->dados[(indice - 1) / 2 ].vertice] = indice;
        troca(&heap->dados[indice],&heap->dados[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }

}

int main(void){

    return 0;
}
