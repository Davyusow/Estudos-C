#include "stdio.h"

int main(void){
    int cont = 10;
    printf("Valor: %d\n",cont--);
    printf("Valor: %d\n",cont);
    printf("Valor: %d\n",--cont);
    cont--;
    cont -= 1;
    cont = cont - 1;
    return 0;
}