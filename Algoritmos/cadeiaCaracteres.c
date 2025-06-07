#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define VAZIO '\0'

typedef struct{
    char* texto;
    int tamanho;
    int teto;
}Vetor;

void iniciar(Vetor *vetor){
    vetor->teto = -1;
}

void juntar(Vetor *vetor,char c){
    if(vetor->teto < vetor->tamanho-1){
        vetor->texto[++vetor->teto] = c;
    }
}

char separar(Vetor *vetor){
    if(vetor->teto >= 0){
        return vetor->texto[vetor->teto--];
    }
    return VAZIO;
}

int comparacao(char aberto,char fechado){
    return (aberto == '(' && fechado == ')') ||
    (aberto == '[' && fechado == ']') ||
    (aberto == '{' && fechado == '}');
}

int bemFormada(Vetor* vetor) {
    Vetor pilha;
    pilha.texto = (char*)malloc(vetor->tamanho * sizeof(char));
    pilha.tamanho = vetor->tamanho;
    iniciar(&pilha);

    for (int i = 0; vetor->texto[i] != VAZIO; i++) {
        char comparado = vetor->texto[i];
        if (comparado == '(' || comparado == '[' || comparado == '{') {
            juntar(&pilha, comparado);
        } else if (comparado == ')' || comparado == ']' || comparado == '}') {
            char topo = separar(&pilha);
            if (!comparacao(topo, comparado)) {
                free(pilha.texto);
                return FALSO;
            }
        }
    }

    int resultado = (pilha.teto == -1) ? VERDADEIRO : FALSO;
    free(pilha.texto);
    return resultado;
}

int main(void){
    Vetor vetor;
    char buffer[1000];

    printf("Digite o texto: ");
    scanf("%999s", buffer);

    vetor.tamanho = strlen(buffer) + 1;
    vetor.texto = (char*)malloc(vetor.tamanho * sizeof(char));
    strcpy(vetor.texto, buffer);

    if (bemFormada(&vetor)) {
        printf("\nbem formada.");
    } else {
        printf("\nmal formada");
    }

    free(vetor.texto);
    return 0;
}