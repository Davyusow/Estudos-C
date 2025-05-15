#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define TAM 25

int main(void){
    srand(time(NULL));
    int vetor1[TAM],vetor2[TAM],somaVetores[TAM];

    //atribuí valores randômicos de 0 a 100 nos vetores 1 e 2, e o resultado da soma é passado para o vetor somaVetores
    for(int indice = 0;indice<TAM;indice++){
        vetor1[indice] = rand()%101;
        vetor2[indice] = rand()%101;
        somaVetores[indice] = vetor1[indice] + vetor2[indice];
    }

    printf("\tVetor 1:\n");
    for(int indice = 0;indice<TAM;indice++)
        printf("valor %i: %i\n",indice+1,vetor1[indice]);

    printf("\tVetor 2:\n");
    for(int indice = 0;indice<TAM;indice++)
        printf("valor %i: %i\n",indice+1,vetor2[indice]);

    printf("\tSoma dos vetores:\n");
    for(int indice = 0;indice<TAM;indice++)
        printf("valor %i: %i\n",indice+1,somaVetores[indice]);

    return 0;
}
