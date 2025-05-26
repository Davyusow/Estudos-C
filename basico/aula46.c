#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    // operador de negação '!' inverte o sentido da operação lógica
    if(a < 0)  
        printf("\n\tValor negativo!\n");
    else if(a != 0) //se o a for diferente de 0, será positivo
        printf("\tValor positivo!\n");
    else        //senão, se for igual a zero
        printf("\tValor igual a 0!\n");    
    return 0;
}