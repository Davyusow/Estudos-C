#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    
    if(a < 0)  //sem chaves apenas a primeira linha esta dentro do if
        printf("\n\tValor negativo!\n");
    else{   //com chaves todo o código dentro das chaves esta dentro do else
        printf("\tValor positivo ou igual a 0!\n");
        printf("\tValor positivo ou igual a 0!\n");
    }
    
        
    return 0;
}