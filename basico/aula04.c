#include "stdio.h"

int main(void){
    int valor1,valor2; //declaração de uma variável do tipo inteiro
    valor1 = 50; //atribuição de um valor para a variável
    printf("Insira um valor: ");
    scanf("%i",&valor1);
    printf("Insira outro valor: ");
    scanf("%i",&valor2);
    /*A função scanf é uma função de entrada, o primeiro argumento é
    o tipo de variável, no caso de %i é inteiro, e o segundo
    o endereço da variável na qual será armazenada, o endereço da
    variável é acessado com & antes do nome da variável*/
    printf("Valor da primeira variável: %i\nValor da segunda variável: %i\n",valor1,valor2);

    return 0;
}