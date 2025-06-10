#include "stdio.h"
#include "string.h"


int main(void){
    char palavra[7] = "abacaxi";
    char *letra = strchr(palavra,'a'); //busca um caractere numa String e retorna o ponteiro da primeira ocorrência
    printf("A primeira ocorrência de \'a\' é %c\n",*letra); // coloca *letra para imprimir o conteúdo corretamente
    printf("A Próxima letra é %c\n",*(letra + 1));
    //aritimética de ponteiros, somando o índice e retornando o próximo endereço da String no próximo índice
    printf("A Próxima letra é %c\n",*(letra + 2));
    printf("A Próxima letra é %c\n",*(letra + 3));
    printf("A Próxima letra é %c\n",*(letra + 4));
    printf("A Próxima letra é %c\n",*(letra + 5));
    printf("A Próxima letra é %c\n",*(letra + 6));

    letra = strrchr(palavra,'a'); //busca um caractere numa String e retorna o ponteiro da última ocorrência
    //se o caractere pesquisado não existir, o resultado será '\0'
    printf("\nA última ocorrência de \'a\' é %c\n",*letra); // coloca *letra para imprimir o conteúdo corretamente
    printf("A Próxima letra é %c\n",*(letra + 1));



    return 0;
}
