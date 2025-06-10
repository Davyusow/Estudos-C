#include "stdio.h"
#include "string.h"

int main(void){
    char palavra[11] = "Ola mundo!";
    char subPalavra[4] = "Ola";
    char *resultado = strstr(palavra,subPalavra);
    //retorna o ponteiro da palavra achada na String do primeiro parâmetro
    //se não for encontrado retorna NULL
    if(resultado != NULL)
        printf("A palavra achada foi: %c,%c,%c\n",*resultado,*(resultado+1),*(resultado+2));
    else
        printf("A palavra não foi encontrada!\n");

    return 0;
}
