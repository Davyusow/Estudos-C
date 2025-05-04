#include "stdio.h"

int main(void){
    printf("Múltiplos de 7 até 9999\n");
    for(int i = 7; i < 9999;i+=7){
        printf("%d ",i);
    }
    return 0;
}
