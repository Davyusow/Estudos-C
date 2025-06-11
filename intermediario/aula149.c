#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int tam = 5;

int somaLinha(int matriz[][tam],int linha){
    int soma = 0;
    for(int x = 0;x<tam;x++){
        soma+= matriz[linha][x];
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
    int somalinha0 =  somaLinha(matriz,0);
    printf("A soma da linha 1 é : %i\n",somalinha0);

    return 0;
}