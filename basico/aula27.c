#include "stdio.h"

int main(void){
    int cont = 10;
    printf("Valor: %d\n",cont++);
    printf("Valor: %d\n",cont);
    printf("Valor: %d\n",++cont);
    cont++; //todos incrementam 1 da mesma maneira, com excessão de cont++, que apenas
    //incrementa após o uso da variável
    cont += 1;
    cont = cont + 1;

    return 0;
}