#include "stdio.h"

void escrever(char file[]){
    FILE *arquivo = fopen(file,"w");
    if(arquivo){
        char letra;
        printf("Digite um texto e pressione enter ao finalizar: ");
        scanf("%c", &letra);
        while (letra != '\n') {
            fputc(letra,arquivo);
            scanf("%c", &letra);
        }
    }else
        printf("\nErro ao abrir o arquivo!\n");
    fclose(arquivo);
}

void ler(char file[]){
    FILE *arquivo = fopen(file,"r");
    if(arquivo){
        rewind(arquivo);
        char letra;
        while(!feof(arquivo)){
            letra = fgetc(arquivo);
            printf("%c", letra);
        }
    }else
        printf("\nErro ao abrir o arquivo!\n");
    fclose(arquivo);
}

int main(void){
    char textinho[] = "resources/aula210.txt";
    escrever(textinho);
    ler(textinho);

    return 0;
}
