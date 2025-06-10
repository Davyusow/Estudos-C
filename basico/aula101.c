#include "stdio.h"

int main(void){
    int contador;
    int valores[10];

    for(contador = 0;contador<10;contador++){
        printf("Valor %i: ",contador+1);
        scanf(" %i",&valores[contador]);
    }
    printf("\n");
    for(contador = 0;contador<10;contador++){
        printf("Valor %i: ",valores[contador]+1);
    }

    return 0;
}
