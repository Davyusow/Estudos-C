#include "stdio.h"

int main(void){
    int n1, n2, n3;
    printf("Digite 3 valores inteiros: ");
    scanf("%i%i%i",&n1,&n2,&n3);    //é possível ler vários valores no scanf
    printf("Valores imprimidos: %i, %i, %i",n1,n2,n3);
    return 0;
}
