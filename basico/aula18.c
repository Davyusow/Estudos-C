#include "stdio.h"

int main(void){
    int x = 2147483647;
    printf("Valor antes do incremento: %d",x);
    x++;
    printf("\nValor após o incremento: %d\n",x);    //ultrapassa o limite do int
    return 0;
}