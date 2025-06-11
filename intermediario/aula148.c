#include "stdio.h"

int idade2 = 35; //variáveç global

void imprimir(int id){
    //printf("Idade: %i\n",idade); //não funciona pois a idade não existe neste procecimento
    printf("Idade: %i\n",id); //cria uma cópia da variável da main e agora sim funciona
    printf("Idade2: %i\n",idade2);
}


int main(void){

    int idade = 25;

    printf("Idade: %i\n",idade); //variável local da main
    imprimir(idade);
    printf("Idade2: %i\n",idade2);
    imprimir(idade2); //idade2 esta presente em todas as partes do código
    return 0;
}