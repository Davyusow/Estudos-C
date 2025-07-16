#include "stdio.h"
#include "string.h"

void escrever(char file[]){
    FILE *arquivo = fopen(file,"w");
    if(arquivo){
        char texto[500];
        printf("Digite uma frase: ");
        //scanf(" %499[^\n]", texto); //lê 500 caracteres até o enter (obs: causou loop infinito!)
        fgets(texto,sizeof(texto),stdin);
        while(strlen(texto) > 1){ //apenas para quando é digitado um único caracter
            fputs(texto,arquivo); //adiciona o texto(String) no arquivo
            //scanf(" %499[^\n]", texto);
            fgets(texto,sizeof(texto),stdin);
            //printf("\n <!--Dentro do while ---!>"); //loop infinito!
        }
        fclose(arquivo);
    }else
        printf("\nErro ao abrir o arquivo!\n");
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
        fclose(arquivo);
    }else
        printf("\nErro ao abrir o arquivo!\n");
}

int main(void){
    char textinho[] = "resources/aula210.txt";
    escrever(textinho);
    ler(textinho);

    return 0;
}
