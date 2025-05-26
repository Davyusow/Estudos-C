#include "stdio.h"

int main(void){
    long int x = 2147483647; //o inteiro agora armazena 8 bytes (64 bits)
    printf("Tamanho: %d\n",sizeof x);
    printf("Valor antes do incremento: %li",x);     //%li permite imprimir os valores do long int com 64 bits
    x++;
    printf("\nValor após o incremento: %li\n",x);
    return 0;
}