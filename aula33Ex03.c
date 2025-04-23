#include "stdio.h"

int main(void){
    int a,b;
    printf("Digite o valor de a: ");
    scanf("%i",&a);
    printf("Digite o valor de b: ");
    scanf("%i",&b);
    
    a = a + b;
    b = a - b;
    a = a - b;

    //a = 3; b = 5;
    printf("Valor de a: %i\nValor de b: %i\n",a,b);
    return 0;
}