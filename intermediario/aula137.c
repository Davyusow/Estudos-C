#include "stdio.h"
#include "string.h"

int main(void){
    char palavra1[20] = "Saudações";
    char palavra2[20] = "Apresentações";
    printf("Palavra 1: %s,Palavra2: %s\n",palavra1,palavra2);
    strcpy(palavra1,palavra2); //o primeiro parâmetro recebe o valor do segundo
    printf("Palavra 1: %s,Palavra2: %s\n",palavra1,palavra2);
}
