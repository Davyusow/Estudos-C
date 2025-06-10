#include "stdio.h"

int main(void){// o próprio int main é uma função

    int tam = printf("Olá mundo!");
    printf("\n %i",tam);
    //printf é uma função, onde os valores dentro do parênteses são argumentos/parâmetros
    //e tem um retorno int da quantidade de caracteres imprimidos na tela

    return 0; //retornar quer dizer que a função termina sem problemas
    //qualquer outro valor pode ser personalizado/interpretado como um debug de um erro(semelhante ao bash)
}
