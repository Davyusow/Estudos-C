#include "stdio.h"

int main(void){

    FILE *arquivo; 
    char letra;

    arquivo = fopen("texto.txt","w+"); //abre um arquivo no modo escrita e leitura
    
    if(arquivo == NULL){
        printf("Arquivo não existe!");
        return 1;
    }
    else{
        printf("Digite um texto e pressione enter ao finalizar: ");
        scanf("%c", &letra);
        while (letra != '\n') {
            fputc(letra,arquivo);
            scanf("%c", &letra);
        }
        
        rewind(arquivo); //volta para o início do arquivo
        //necessário pois agora o file aponta para o enter '\n'
        printf("\nTexto lido do arquivo: \n");
        while (!feof(arquivo)){ //feof (file: end of file) enquanto não chegar no fim do arquivo
            letra = fgetc(arquivo); //lê o próximo caracter
            printf("%c", letra);
        }
        
    }
    fclose(arquivo);
    return 0;
}
