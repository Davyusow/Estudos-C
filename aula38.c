#include "stdio.h"
#include "stdbool.h"
    // a > b (a maior que b)
    // a < b (a menor que b)
    // a >= b (a maior ou igual a b)
    // a <= b (a menor ou igual a b)
    // a == b (a igual a b)
    // a != b (a diferente de b)

int main(void){
    int a = 10, b = 8;
    int x = a == b;
    printf("Resultado = %d\n",x);   //1 verdadeiro, //0 falso

    return 0;
}