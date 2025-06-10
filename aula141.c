#include "stdio.h"
#include "string.h"

int main(void){
    char frase[34] = "Uma frase consideravelmente grande";
    char *ponteiro;
    ponteiro = strtok(frase," ");
    //separa as palavras apartir do delimitador, no caso o espaço " ", porém podem ser passados mais de um
    // em um texto convencional o padrão seria strtok(frase,",.!?:; ") ou algo parecido
    while(ponteiro){ //enquanto o ponteiro não for nulo
        printf("\033[31mToken: \033[m %s\n",ponteiro);
        //deixar coloridinho é que nem o python
        ponteiro = strtok(NULL, " "); //aponta para o próximo
    }
    return 0;
}
