#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define TAM 10

int main(void){
    srand(time(NULL));
    int *vetor = (int *)  malloc(sizeof(int)*1);
    vetor[0] = 11;
    vetor =(int* ) realloc(vetor,TAM*sizeof(int));
    for(int i = 1;i < TAM;i++){
        vetor[i] = rand()%11;
    }
    
    for(int i = 0;i < TAM;i++){
        printf("%i ",vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}