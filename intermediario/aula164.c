#include "stdio.h"

void binario(int num){
    if(num == 0)
        printf("0");
    else
    binario(num/2);
    printf("%d",num/2);
}

int main(void){
    int n = 10;
    printf("%b",n);

    return 0;
}
