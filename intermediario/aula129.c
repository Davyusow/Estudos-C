#include "stdio.h"

int main(void){
    char palavras[] = {"Um texto bem maiorzinho"};
    char nome[100]; //melhor extrapolar um pouco pra ter certeza que não vai perda de dados
    printf("%s\n",palavras);
    //scanf(" %[^\n]",nome); //lê tudo até o enter ser pressionado
    scanf(" %80[^\n]",nome); //limita em 80 caractéres a leitura do scanf, o restante é perdido
    printf("Olá! %s",nome);

    return 0;
}
