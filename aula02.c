#include "stdio.h"

int main(void){
    printf("Olá! Seja Bem Vindo!\n"); //a função 'printf();' imprime variáveis e valores na tela com formatações
    // \n pula uma linha
    //printf(); é uma impressão de saída
    printf("\n--------------------------------\n");
    printf("Opção N° 1: avançar\n");
    printf("Opção N° 2: voltar\n");
    printf("Opção N° 3: sair");
    printf("\n--------------------------------\n");
    //%i separa o local para a impressão de um valor inteiro (int)
    //o printf retorna valores inteiros:
    printf("Valor recebido: %i",printf("Oi"));  //é possível fazer uma função print dela mesma
    //o printf(); retorna o número de caractéres inclusos nas aspas, incluindo também \n e \n por exemplo
    return 0;
}
