#include "stdio.h"

int main(void){
    float dolar,real;
    printf("Digite uma quantia em reais: ");
    scanf("%f",&real);
    dolar = real/5.30;
    printf("R$%.2f em dolar é: $%.2f\n",real,dolar);

    return 0;
}