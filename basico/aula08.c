#include "stdio.h"
#include "stdlib.h"

int main(void){
    char letra;
    printf("Digite um caractere: ");
    letra = getc(stdin);    //semelhante ao 'getchar();', com a diferença que especifica a entrada no argumento, neste caso a entrada padrão (teclado)
    printf("Caractere lido: %c\n",letra);
    return 0;
}