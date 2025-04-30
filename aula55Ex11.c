#include "stdio.h"

int main(void){
    float real;
    printf("Insira o seu saldo em reais: R$");
    scanf("%f",&real);
    printf("Com R$%.2f, é possível comprar $%.2f doláres\n",real,(real/5.30));
}
