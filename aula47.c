#include "stdio.h"

int main(void){
    int idade;
    char sexo;
    
    printf("Digite seu sexo f ou m: ");
    scanf("%c",&sexo);
    printf("Digite a sua idade: ");
    scanf("%i",&idade);

    if(sexo == 'm' && idade == 18)
        printf("Alistamento obrigatório!\n");
    else
        printf("Dispensado!\n");

    return 0;
}