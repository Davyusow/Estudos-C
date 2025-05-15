#include "stdio.h"

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

#define TAM 20
#define METADE 10

int main(void){
    int vetor[TAM];
    int vetorInvertido[TAM];

    for(int indice = 0;indice<TAM;indice++){
        printf("%2i° ",indice+1);
        vetor[indice] = lerInteiro("valor do vetor: ");
    }

    for(int indice = 0;indice<METADE;indice++){ //atribui o inverso do vetor no vetor invertido
        vetorInvertido[indice] = vetor[TAM-indice-1];
        vetorInvertido[TAM-indice-1] = vetor[indice];
    }

    printf("\tVetor Original\n");
    for(int indice = 0;indice<TAM;indice++){
        printf("Valor %2i: %i\n",indice+1,vetor[indice]);
    }

    printf("\tVetor Invertido\n");
    for(int indice = 0;indice<TAM;indice++){
        printf("Valor %2i: %i\n",indice+1,vetorInvertido[indice]);
    }

    return 0;
}
