#include "stdio.h"

int main(void){
    float x = 3.1415;
    long double y = 3.141536723465;

    printf("Tamanho de y: %d\n",sizeof y);
    printf("Valor de y: %.10Lf\n",y);
    printf("Valor de x: %f\n",x);

    return 0;
}