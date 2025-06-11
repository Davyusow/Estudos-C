#include "stdio.h"

//tipo de retorno - identificador - argumentos
int tamanhoString(char string[]){
    int tamanho = 0;
    while(string[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho; //o valor retornado
}

int main(void){
    char palavra[25] = "Uma frase qualquer";
    int tamanho = tamanhoString(palavra);
    printf("\"%s\" tem %i caracteres\n",palavra,tamanho);
    return 0;
}