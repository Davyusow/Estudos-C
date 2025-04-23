#include "stdio.h"

int main(void){
    //somente no windows (pelo menos com mingw)
    //setlocale(LC_ALL,"Portuguese");//LC_ALL é uma constante que permite todas as localizações
    //o "" faz usar o padrão do sistema operacional
    //"Portuguese" força a usar o português brasileiro
    printf("Coração\n");    //no windows o 'ç' e 'ã' saem quebrados
    //unsigned char letra = 'a';
    return 0;
}