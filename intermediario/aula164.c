#include "stdio.h"

void binario(int num){
    if(num == 0)
        printf("%i",num);
    else{
        binario(num/2);
        printf("%d",num%2);
    }
}

int main(void){
    int n = 0;
    printf("Digite um valor decimal: ");
    scanf("%i",&n);

    printf("Decimal: %i\nBinário: ",n);
    binario(n);

    return 0;
}
