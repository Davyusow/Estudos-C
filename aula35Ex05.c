#include "stdio.h"

int main(void){
    int dias;    
    printf("Quantos dias o encanador trabalhou? ");
    scanf("%i",&dias);
    float imposto = 0.08;
    float valor = (float)(dias*45 - dias*45*imposto);
    
    printf("\nO valor total a ser pago é de: R$%.2f\n",valor);
    return 0;
}