#include "stdio.h"

int main(void){
    char letra;
    printf("Digite um caractere: ");
    letra = fgetc(stdin);   /*semelhante ao getc, com a diferença que é normalmente usado
    para leitura de arquivos e não de entradas de teclado, mas pode fazer isso com o parâmetro stdin*/
    printf("Caractere lido: %c\n",letra);
    return 0;
}
