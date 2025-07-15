#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LINHAS 4
#define COLUNAS 3

int main(void){

    srand(time(NULL));
    int **matriz, linha, coluna;
    matriz = malloc(sizeof(int *) * LINHAS); //aloca 4 vetores na memória

    for(linha = 0; linha < LINHAS; linha++)
        matriz[linha] = malloc(sizeof(int) * COLUNAS); //aloca os vetores matriz


    for(linha = 0 ; linha < LINHAS; linha++)
        for(coluna = 0 ;coluna < COLUNAS;coluna++)
            *(*(matriz + linha) + coluna) = rand() % 100;

    for(linha = 0 ; linha < LINHAS; linha++){
        for(coluna = 0 ;coluna < COLUNAS;coluna++){
            printf("%-2i ",*(*(matriz + linha) + coluna));
        }
        printf("\n");
    } 


    return 0;
}
