#include "stdio.h"

int main(void){
    int a = 10; int b = 20;
    int resto = b % a;  // é a operação de mod (retorna o resto da divisão de a por b)
    printf("O resto da divisçao é %i\n",resto);
    return 0;
}