#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct No{
    int chave;
    struct No* prox;
}No;

typedef struct{
    No* primeiro;
}Lista;

void imprimir(Lista lista){
    No* aux = lista.primeiro;
    while(aux != NULL){
        printf("Chave: %i, ",aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

No* buscar(int chave,Lista* lista){
    No* aux = lista->primeiro;
    No* anterior = NULL;
    if(aux != NULL){    
        while(aux != NULL && aux->chave != chave){
            anterior = aux;
            aux = aux->prox;
        }
    }else{
        printf("Nó não encontrado\n");
    }
    return aux;
}

void inserir(int chave,Lista* lista){
    if(buscar(chave, lista)==NULL){
        No* novo = (No*)malloc(sizeof(No));
        novo->chave = chave;
        novo->prox = lista->primeiro;
        lista->primeiro = novo;
    }else{
        printf("Nó já existe\n");
    }
}

void remover(int chave, Lista* lista) {
    No* aux = lista->primeiro;
    No* anterior = NULL;

    while (aux != NULL && aux->chave != chave) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux != NULL) {
        if (anterior == NULL) {
            lista->primeiro = aux->prox;
        } else {
            anterior->prox = aux->prox;
        }
        free(aux);
    } else {
        printf("Nó não encontrado\n");
    }
}


int main(void){
    Lista lista; 
    lista.primeiro = NULL;

    inserir(10, &lista);
    inserir(20, &lista);
    inserir(5, &lista);
    imprimir(lista);
    remover(10,&lista);
    imprimir(lista);

    return 0;
}