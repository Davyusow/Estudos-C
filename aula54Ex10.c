#include "stdio.h"

int main(void){
    int n1;
    printf("Insira um número: ");
    scanf("%i",&n1);
    int cont = 0;
    if(n1 % 2 == 0){
        printf("%i é divisível por 2\n",n1);
        cont++;
    }if(n1 % 3 == 0){
        printf("%i é divisível por 3\n",n1);
        cont++;
    }if(n1 % 5 == 0){
        printf("%i é divisível por 5\n",n1);
        cont++;
    }
    if(cont == 0){
        printf("%i não é divisível por 2, 3 nem 5\n",n1);
    }

    return 0;
}
