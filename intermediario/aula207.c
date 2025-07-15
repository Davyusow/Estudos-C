#include "stdio.h"
#include "stdlib.h"

int main(void){
    int *vetor1, *vetor2;
    vetor1 = malloc(10 * sizeof(int));
    vetor2 = calloc(10, sizeof(int));

    printf("Com malloc: \n");
    for(int linha = 0; linha < 10; linha++){
        printf("%i ",vetor1[linha]);
    }
    //normalmente o malloc põe lixo de memória nos valores alocados
    //enquanto o calloc põe 0 como valor padrão
    //aqui no gcc 15.1.1 não teve esta diferença
    printf("\nCom calloc: \n");
    for(int linha = 0; linha < 10; linha++){
        printf("%i ",vetor2[linha]);
    }

    return 0;
}
