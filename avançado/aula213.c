#include "stdio.h"

#define CONTINUAR 1

void escrever(char file[]){
    FILE *arquivo = fopen(file,"w");
    char nome[100];
    int idade,opcao;
    float altura;

    if(arquivo){
        do{
            printf("Digite um nome: ");
            scanf(" %99[^\n]",nome);
            printf("Digite uma idade: ");
            scanf(" %i",&idade);
            printf("Digite uma altura: ");
            scanf(" %f",&altura);
            fprintf(arquivo,"Nome: %s\nIdade: %i\nAltura: %.2f\n",nome,idade,altura);
            printf("Digite 1 para adicionar outro registro: ");
            scanf(" %i",&opcao);
        }while(opcao == CONTINUAR);
        //imprime o String de maneira formatada no arquivo
        fclose(arquivo);
    }else
        printf("\nErro ao abrir o arquivo!\n");
}

int main(void){
    char textinho[] = "resources/aula213.txt";
    escrever(textinho);

    return 0;
}
