#include "stdio.h"

#define TAM 50

typedef struct Contato{
    char nome[TAM];
    int dia, mes, ano;
}Contato;

void escrever(char file[]){
    Contato contato;
    FILE *arquivo = fopen(file, "ab"); //anexa em arquivo binário
    if(arquivo){
        printf("Digite o nome: ");
        fgets(contato.nome,TAM,stdin);
        //getchar();
        printf("Digite a sua data de nascimento dd/mm/aaaa: ");
        scanf(" %i/%i/%i",&contato.dia,&contato.mes,&contato.ano);
        getchar();
        fwrite(&contato,sizeof(Contato),1,arquivo); //escreve um arquivo em binário
        // primeiro parâmetro: virá de qual variável?
        // segundo parâmetro: Qual o tamanho de cada dado?
        // terceiro parâmetro: Quantos dados?
        // quarto parâmetro: em qual arquivo?
        fclose(arquivo);
    }else{
        printf("\nErro ao abrir arquivo\n");
        return;
    }
}

int main(void){
    char arquivo[] = {"resources/aula218.dat"};
    escrever(arquivo);
    return 0;
}
