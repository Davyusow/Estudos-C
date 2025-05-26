#include "stdio.h"

int main(void){
    char a,b;
    
    printf("Digite uma letra: ");
    scanf("%c",&a);
    getchar(); //captura o caractere entre as duas leituras
    printf("Digite outra letra: ");
    scanf("%c",&b);
    printf("Primeira letera %c\nSegunda Letra: %c\n",a,b);
    return 0;
}
