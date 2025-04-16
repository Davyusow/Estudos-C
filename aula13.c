#include "stdio.h"

int main(void){
    char a,b;
    printf("Digite duas letras: ");
    scanf("%c %c",&a,&b);
    /*Espaço entre os %c serve para desconsiderar o ENTER, TAB e ESPAÇO
     evite usar a função fflush();
     essa que serve para limpar o buffer do teclado, que apenas funciona
     no sistema operacional Windows, além dele não funcionar em
     todos os casos possíveis*/
    printf("Primeira letra: %c\nSegunda Letra: %c\n",a,b);
    return 0;
}