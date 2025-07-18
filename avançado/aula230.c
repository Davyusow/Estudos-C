#include <stdio.h>
#include <stdlib.h>
#include "headers/pilha.c" //chama o arquivo pilha.c

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
