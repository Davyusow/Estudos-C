#include "stdio.h"

int main(void){
    short int x = 0;    //armaze valores em 2 bytes ao invés de 4, indo de -32768 a 32.767
    int y = 0;
    printf("Tamanho de um int na memória: %i bytes\n", sizeof y);
    printf("Tamanho em meória de um short int: %hi bytes\n", sizeof x); //%hi também formata inteiros

    return 0;
}