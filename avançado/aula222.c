#include "stdio.h"

int main(void){
    char file[] = "resources/aula222.txt";
    FILE *arquivo = fopen(file,"r");
    if(arquivo){
        printf("\nArquivo aberto com sucesso!\n");
        fclose(arquivo);

        if(remove(file)){ //remove um arquivo passando seu endereço
            printf("\nArquivo removido com sucesso!\n");
        }else{
            printf("\nArquivo não existe!\n");
        }
    }else {
        printf("\nErro ao tentar abrir o arquivo\n");
    }

    return 0;
}
