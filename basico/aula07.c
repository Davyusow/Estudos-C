#include "stdio.h"

int main(void){
    char letra;
    printf("Digite uma letra: ");
    letra = getchar();  //é uma função de entrada que lê o primeiro caractér
    //neste caso o valor esta sendo atribuido na variável letra
    printf("A letra foi: %c\n",letra);
    return 0;
}