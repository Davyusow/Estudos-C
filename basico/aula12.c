#include "stdio.h"

int main(void){
    char sexo; short idade; float peso,altura;
    printf("\nInsira sua idade: "); scanf("%i",&idade);
    printf("\nInsira seu peso (Kg): "); scanf("%f",&peso);
    printf("\nInsira sua altura (m): "); scanf("%f",&altura);
    //printf("Insira seu sexo [F/M]: "); sexo = getchar();    //o caractere for lido depois de qualquer outro valor após
    //o usuaário pressionar enter, o enter será considerado um caractere e será armazenado
    //pois no buffer do teclado o \n (caractere do enter) irá ser a próxima tecla
    //para evitar isso podemos fazer deste jeito:
    printf("Insira seu sexo [F/M]: "); scanf(" %c",&sexo);  //colocando um espaço antes do %c faz com que ignore um espaço, enter ou tab
    printf("\nO usuário é do sexo %c, tem %i anos, pesa %.1fKg, e tem %.2fm de altura.\n",sexo,idade,peso,altura);
    return 0;
}
