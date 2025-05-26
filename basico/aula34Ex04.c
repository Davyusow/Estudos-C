#include "stdio.h"

int main(void){
    float despesa; float gorjeta;int quantidade;
    printf("Insira o valor da despesa: ");
    scanf("%f",&despesa);
    printf("Insira a porcentagem da gorjeta: ");
    scanf(" %f",&gorjeta);
    printf("Quantas pessoas pagaram? ");
    scanf(" %i",&quantidade);
    quantidade = (float)quantidade;
    gorjeta = (gorjeta/100)*despesa;
    despesa = (despesa + gorjeta)/quantidade;
    
    printf("\nO total a se pagar entre %i pessoas é: R$%.2f\n",quantidade,despesa);

    return 0;
}