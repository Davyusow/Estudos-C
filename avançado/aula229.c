#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

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

int fatorial(int num){
    No *pilha = NULL;
    No *remover = NULL;

    while(num > 1){
        pilha = empilhar(pilha,num--);
    }
    imprimir(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num;
}

int main(void){
    int valor;
    printf("Digite um valor inteiro para calcular seu fatorial: ");
    scanf(" %i",&valor);
    printf("\nO resultado é: %i",fatorial(valor));
    return 0;
}
