#include "stdio.h"
#include "string.h"

int main(void){
    int tam;
    char formatador[10] = {"%"} ,config[10];
    
    printf("Digite aqui o tamanho do string: ");
    scanf(" %i",&tam);

    //sprintf(config, "%d[^\n]",tam); //imprime o conteúdo em uma variável
    snprintf(config,10, "%d[^\n]",tam); //imprime o conteúdo em uma variável passando um tamanho máximo da string
    //serve para neste caso, evitar valores muito grandes no parâmetro
    //mas irá sair uma string mal formada, causando um erro

    strcat(formatador,config);  //fica por exemplo "%50[^\n]"

    char palavra[tam];
    getchar();
    printf("Digite aqui a frase: ");
    scanf(formatador,palavra);
    printf("%s\n",palavra);
    

    return 0;
}