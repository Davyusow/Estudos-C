#include "string.h"
#include "stdio.h"

int main(void){
    char palavras[100] = "Imagine que aqui tem um texto enorme e você quer saber o tamanho dela";
    int tamanho = strlen(palavras); //retorna o tamanho da String
    printf("A String: \n\"%s\"\n tem %i letras.",palavras,tamanho);
    return 0;
}
