#include "stdio.h"
int main(void){
    int contador = 0;
    char palavras[100] = "Imagine que aqui tem um texto enorme e você quer saber o tamanho dela";

    while(palavras[contador] !=  '\0'){
        contador++;
    }
    printf("A String: \n\"%s\"\n tem %i letras.",palavras,--contador);
    return 0;
}
