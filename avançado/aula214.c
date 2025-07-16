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

void ler(char file[]){
    FILE *arquivo = fopen(file,"r");
    char nome[100];
    int idade;
    float altura;

    //quando não conseguir ler retorna -1
    while(fscanf(arquivo,"Nome: %99[^\n]\nIdade: %i\nAltura: %f\n" ,
        nome, &idade, &altura) != EOF){ //EOF constante do fim do arquivo, mas também poderia ser -1

        //basicamente um ctrl + c ctrl + v do fprintf, só copiar a formatação
        //além disso retorna a quantidade de variáveis lidas
        printf("Nome: %s\nIdade: %i\nAltura: %.2f\n",nome, idade, altura);
    }
    fclose(arquivo);
}

int main(void){
    char textinho[] = "resources/aula213.txt";
    escrever(textinho);
    ler(textinho);


    return 0;
}
