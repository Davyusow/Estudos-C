#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

// ao chamar include com <lib> ele chama apartir do diretório do compilador
// com "lib" ele também busca localmente

No *empilhar(No *pilha,int num){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }else
        printf("Erro ao alocar memória!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;
    if(pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }else
        printf("Pilha vazia!\n");
    return remover;
}

void imprimir(No *pilha){
    printf("1");
    while(pilha != NULL){
        printf(" -> %i",pilha->valor);
        pilha = pilha->proximo;
    }
}
