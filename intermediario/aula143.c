#include "stdio.h"
#include <string.h>

#define IGUAL 0


int main(void){
    char palavra[30],copia[30];
    int i,iguais = 0;
    printf("\033[31mDigite uma palavra:\033[m ");
    scanf("%s",palavra);

    int tamanho = strlen(palavra);
    for(i = 0;i < strlen(palavra);i++){
        copia[i] = palavra[tamanho - 1];
        tamanho--;
    }
    copia[i] = '\0';

    tamanho = strlen(palavra);
    for(i = 0;i < tamanho;i++){
        if(palavra[i] == copia[i])
            iguais++;
    }
    if(iguais == tamanho)
        printf("Palíndroma");
    else
        printf("Não é Palíndroma");

    return 0;
}
