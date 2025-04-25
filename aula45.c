#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    

   a < 0 ? printf("\n\tValor negativo!\n") : a == 0 ? printf("\tValor igual a 0!\n") : printf("\tValor positivo!");    //operador ternário
    //operador ternário alinhado            //outro if
        
    return 0;
}