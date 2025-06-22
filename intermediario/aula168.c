#include "stdio.h"

typedef struct{
    int idade;
    char sexo;
    char nome[100];
}Pessoa;

int main(void){
    Pessoa pessoa1;
    
    printf("Digite seu nome: ");
    fgets(pessoa1.nome,100,stdin);
    
    printf("Digite sua idade: ");
    scanf(" %i",&pessoa1.idade);

    printf("Digite seu sexo: ");
    scanf(" %c",&pessoa1.sexo);

    

    printf("Nome: %sIdade: %i\nSexo: %c\n"
    ,pessoa1.nome,pessoa1.idade,pessoa1.sexo);


    return 0;
}