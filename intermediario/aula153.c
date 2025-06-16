#include "stdio.h"



void procedimentoDecrescente(int num){
    printf("número = %i\n",num);
    if(num > 0)
        procedimentoDecrescente(num-1);
}

void procedimentoCrescente(int num){
    if(num > 0){
        procedimentoCrescente(num-1); //ao inverter os passos, os procedimentos irão ficar esperando até que o próximo termine
        //apenas quando o último terminar ele irá fazer o comando debaixo, abrindo espaço para os próximos, como uma pilha
        printf("número = %i\n",num);
    }
}


int main(void){
    printf("Digite um número :");
    int tam;
    scanf(" %i",&tam);
    procedimentoDecrescente(tam);
    printf("\nCrescente: \n");
    procedimentoCrescente(tam);
    return 0;
}