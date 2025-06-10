#include "stdio.h"

int main(void){
    char nome[20];
    printf("Digite seu nome: ");
    fgets(nome,20,stdin); //"file get string" mas também serve para ler input do teclado
    //salva no vetor nome, com tamanho máximo de 20 caractéres apartir do input padrão, no caso, o teclado
    //no índice 19 será posto '\0' limitando o tamanho do vetor
    printf("\nNome: %s",nome);
    return 0;
}
