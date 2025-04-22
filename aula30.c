#include "stdio.h"

int main(void){
    printf("Coração\n");    //no windows o 'ç' e 'ã' saem quebrados
    unsigned char letra = 'ã';
    printf("%c\n",letra);
    return;
}