#include "stdio.h"
#include "string.h"

int main(void){
    char palavra1[20] = "Saudações";
    char palavra2[20] = "Apresentações";
    //retorna 0,-1 ou 1
    // 0 quando os dois strings são iguais
    // -1 quando o primeiro caractere da primeira string é menor
    // 1 quando o primeiro caractere da segunda string é menor
    if(strcmp(palavra1,palavra2) == 0){
        printf("São iguais\n");
    }else{
        printf("São difenrentes\n");
    }
    return 0;
}
