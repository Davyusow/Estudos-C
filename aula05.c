#include "stdio.h"

int main(void){
    float valor1; double valor2;
    /*O tipo float e double são tipos que armazenam valores de
    números reais, sendo a diferença que float armazena valores
    de 32 bits e o double valores de 64 bits, ou seja, armazena
    valores muito maiores*/
    valor1 = 3.1415;
    printf("valor da minha variável: %.4f\n",valor1); // %.4f formata o valor para imprimir apenas os 4 números depois do ponto
    printf("Digite um número real: \n"); scanf("%lf",&valor2);  // %lf serve para se referir ao double, se lê "long float"
    printf("Valor da segunda variável: %lf\n",valor2);
    return 0;
}
