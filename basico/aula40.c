#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);

    if(a < 0)  //se a for menor que zero
        printf("\n\tValor negativo!\n");
    else
        printf("\tNumero positivo!\n");
    return 0;
}