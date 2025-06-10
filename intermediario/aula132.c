#include "stdio.h"

int main(void){
    char nome[20];
    printf("Digite seu nome: ");
    fgets(nome,20,stdin);
    for(int i = 0;i < 20;i++){
        printf("nome[%i] : %c\n",i,nome[i]);
        if(nome[i] == '\n'){
            printf("Fim da String\n");
        }
        if(nome[i] == '\0'){
            printf("Fim do vetor\n");
            break;
        }
    }
    return 0;
}
