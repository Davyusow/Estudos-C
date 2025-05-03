#include "stdio.h"

int main(void){
    printf("Digite um valor maior que 0: ");
    int contador; scanf("%i",&contador);

    while (contador > 0){
        printf("%d ",contador--);
    }



    return 0;
}
