#include "stdio.h"

int main(void){
    char nomes[5][25]; //guarda 5 nomes de 25 caracteres cada

    for(int i = 0;i < 5;i++){
        printf("\033[31mDigite o %i° nome: \033[m",i+1);
        fgets(nomes[i],25,stdin);
    }

    for(int i = 0;i < 5;i++){
        printf("\033[31mNome %i\033[m: %s\n",i+1,nomes[i]);
    }

    return 0;
}
