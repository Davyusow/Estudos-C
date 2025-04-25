#include "stdio.h"

int main(void){
    int a;
    printf("Insira o valor de a: ");
    scanf("%i",&a);
    printf("Resultado lógico: %d\n",a < 0); //1 é true e 0 é false
    //qualquer valor diferente de 0 irá significar verdadeiro, ex:
    //if(0.1) irá retornar verdadeiro, apenas if(0) é consisderado falso
    //logo (a < 0 == 1) também é um teste lógico válido, porém é feito mais operações
    if(a < 0)  //se a for menor que zero
        printf("\n\tValor negativo!\n");
    else
        printf("\tNumero positivo!\n");
    return 0;
}