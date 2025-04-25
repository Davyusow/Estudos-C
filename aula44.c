#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    
    if(a < 0)  
        printf("\n\tValor negativo!\n");
    else if(a == 0) //adiciona um if com condição, "senão se"
        printf("\tValor igual a 0!\n");
    else
        printf("\tValor positivo!\n");
    
        
    return 0;
}