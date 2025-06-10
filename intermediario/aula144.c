#include "stdio.h"
#include "string.h"

#define FALSE 0
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define NEUTRO "\033[m"

int main(){
    char palavra[50], copia[50];
    int indice,tamanho, contador, diferente = 0;
    printf("%s Frase %s",VERMELHO,NEUTRO);
    printf("%sDigite uma frase%s: ",VERMELHO,NEUTRO);
    scanf("%49[^\n]", palavra);

    for(indice = 0,contador = 0; indice < strlen(palavra); indice++){
        if(palavra[indice] != '!' && palavra[indice] != '?' && palavra[indice] != ' ' && palavra[indice] != '.')
            copia[contador++] = palavra[indice];
    }
    copia[contador] = '\0';

    printf("%sPalavra %s: %s\n",VERMELHO,NEUTRO,palavra);
    printf("%sCópia %s: %s\n",VERMELHO,NEUTRO,copia);

    tamanho = strlen(copia);
    tamanho--;
    for(int indice = 0; indice < strlen(copia); indice++){
        if(copia[indice] != copia[tamanho])
            diferente++;
        tamanho--;
    }

    if(diferente == FALSE)
        printf("\n%sPalíndroma%s\n",VERDE,NEUTRO);
    else
        printf("\n%sNão é palíndroma%s\n",VERMELHO,NEUTRO);

    return 0;
}
