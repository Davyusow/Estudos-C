#include "stdio.h"

int main(void){
    int a,b,temp;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    printf("\nInsira o valor de b: ");
    scanf(" %i",&b);
    temp = a;
    a = b;
    b = temp;
    printf("\nValor de a: %i\nValor de b: %i\n",a,b);

    return 0;
}