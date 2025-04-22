#include "stdio.h"

int main(void){
    int x = 10; int y = 20;
    int soma = x + y;
    int subtracao = x - y;
    int multiplicacao = x * y;
    float divisao = y / x ;
    printf("Soma = %i\nSubtracao = %i\nMultiplicacao = %i\nDivisao = %.2f\n",soma,subtracao,multiplicacao,divisao);

    return 0;
}