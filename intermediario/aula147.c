#include "stdio.h"


int tamanhoString(char string[]){
    int tamanho = 0;
    while(string[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho; 
}

void imprimirString(char string[]){
    int tamanho = tamanhoString(string);
    for(int indice = 0;indice<tamanho;indice++){
        printf("%c",string[indice]);
    }
    printf("\n");
}

int main(void){
    char palavra[25] = "Uma frase qualquer";
    int tamanho = tamanhoString(palavra);
    imprimirString(palavra);
    printf("a palavra tem %i caracteres\n",tamanho);
    
    return 0;
}