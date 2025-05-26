#include "stdio.h"

int main(void){
   unsigned long long graosArroz = 1;
    for(int contador = 0; contador < 63;contador++){
        graosArroz *=2;
        printf("%ld \n",graosArroz);
    }

    printf("A rainha terá que dar %lld grãos de arroz",graosArroz-1);
    return 0;
}
