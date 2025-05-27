#include "stdio.h"

int main(void){
    char palavras[] = {"Um texto bem maiorzinho"};
    char nome[100]; //melhor extrapolar um pouco pra ter certeza que não vai perda de dados
    printf("%s\n",palavras);
    scanf(" %s",nome);
    printf("Olá! %s",nome);

    return 0;
}