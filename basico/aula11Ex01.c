#include "stdio.h"

int main(void){
    char sexo; short idade; float peso,altura;
    printf("Insira seu sexo [F/M]: "); sexo = getchar();
    printf("\nInsira sua idade: "); scanf("%i",&idade);
    printf("\nInsira seu peso (Kg): "); scanf("%f",&peso);
    printf("\nInsira sua altura (m): "); scanf("%f",&altura);
    printf("\nO usuário é do sexo %c, tem %i anos, pesa %.1fKg, e tem %.2fm de altura.\n",sexo,idade,peso,altura);
    return 0;
}
