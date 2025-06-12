#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int tam = 5;

int somaLinha(int matriz[][tam],int coluna){
    int soma = 0;
    for(int x = 0;x<tam;x++){
        soma+= matriz[x][coluna];
    }
    return soma;
}

void imprimir(int matriz[][tam]){
    for(int x = 0;x<tam;x++){
        for(int y =0;y<tam;y++){
            printf("Matriz[%i][%i] = %2i, ",y,x,matriz[x][y]);
        }
        printf("\n");
    }
}

int main(void){
    srand(time(NULL));    
    int matriz[5][5];
    int tamanho = 5; 
    
    for(int x = 0;x<tamanho;x++){
        for(int y =0;y<tamanho;y++){
            matriz[x][y] = rand() % 11;
        }
    }
    imprimir(matriz);

    for(int indice = 0;indice < tam;indice++)
        printf("A soma da coluna %i é : %i\n",indice,somaLinha(matriz,indice));

    return 0;
}