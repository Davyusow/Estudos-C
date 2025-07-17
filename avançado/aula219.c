#include "stdio.h"

#define TAM 50

typedef struct Contato{
    char nome[TAM];
    int dia, mes, ano;
}Contato;

void escrever(char file[]){
    Contato contato;
    FILE *arquivo = fopen(file, "ab");
    if(arquivo){
        printf("Digite o nome: ");
        fgets(contato.nome,TAM,stdin);
        //getchar();
        printf("Digite a sua data de nascimento dd/mm/aaaa: ");
        scanf(" %i/%i/%i",&contato.dia,&contato.mes,&contato.ano);
        getchar();
        fwrite(&contato,sizeof(Contato),1,arquivo);
        fclose(arquivo);
    }else{
        printf("\nErro ao abrir arquivo\n");
        return;
    }
}

void ler(char file[]){
    Contato contato;
    FILE *arquivo = fopen(file,"rb"); //lê um arquivo binário
    if(arquivo){
        //enquanto não chegar no fim do arquivo, e ler algum dado válido...
        while (!feof(arquivo) && fread(&contato,sizeof(Contato),1,arquivo) != 0) { //armazena em uma variável um valor de um arquivo
            //armazena em uma variável um valor de um arquivo
            // primeiro parâmetro: salvar em qual variável?
            // segundo parâmetro: Qual o tamanho de cada dado?
            // terceiro parâmetro: Quantos dados?
            // quarto parâmetro: o dado virá de qual arquivo?
            printf("\nNome: %sData de nascimento: %i/%i/%i\n",contato.nome,contato.dia,contato.mes,contato.ano);
        }
        fclose(arquivo);
    }else{
        printf("\nErro ao abrir arquivo\n");
        return;
    }
}

int main(void){
    char arquivo[] = {"resources/aula218.dat"};
    escrever(arquivo);
    ler(arquivo);
    return 0;
}
