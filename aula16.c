#include "stdio.h"

int main(void){
    
    printf("Tamanho em memória de um tipo int: %i\n",sizeof(int));
    float x = 1.0; 
    printf("Tamanho de um float na memória: %i bytes\n",sizeof(x));
    //sizeof() esta retornando o valor em bytes, neste caso como o int
    //armazena valores em 32 bits, ele retorna 4 bytes que é equivalente
    //porém sizeof não é uma função, e sim um operador, portanto 'sizeof x' é possível
    //mas 'sizeof int' não é possível, por isso fazemos um cast 'sizeof(int)'

    return 0;
}