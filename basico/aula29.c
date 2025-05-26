#include "stdio.h"

int main(void){
    unsigned int x; //aumenta o intervalo de valores para o intervalo negativo
    //ficando assim com o limite de 4.294.967.295, ainda mantendo os 4bytes
    x = 2147483647;
    unsigned short int y = 50000; //semelhante ao unsigned int, ele armazena apenas números
    //positivos em 2 bytes, tendo limite com um pouco mais de 64.000; 
    printf("%li\n",++x);
    printf("Tamanho de x: %i\n",sizeof x);
    printf("%i\n",++y);
    printf("tamanho de y: %hi\n",sizeof y);
    //o short int pode ser formatado no print com %d ou %hi
    //o unsigned short int com %hu ou %d
    //e o unsigned long int com %lu
    return 0;
}