#include "stdio.h"

int main(void){
    char sexo; //tipo que armazena carácteres
    sexo = 'f'; //ao atribuir um carácter ele precisa estar em volta de aspas simples 
    printf("Digite seu sexo [F,M]: ");
    scanf("%c",&sexo);
    printf("\nValor da variável sexo: %c\n",sexo);
    return 0;
}