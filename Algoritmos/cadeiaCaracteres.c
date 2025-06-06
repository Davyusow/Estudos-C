#include "stdio.h"

#define TAM 100
#define VERDADEIRO 1
#define FALSO 0

typedef struct{
    char texto[TAM];
    int teto;
}Vetor;

void iniciar(Vetor *v1){
    v1->teto = -1;
}

void juntar(Vetor *v1,char c){
    if(v1->teto < TAM-1){
        v1->texto[++v1->teto] = c;
    }
}

char separar(Vetor *v1){
    if(v1->teto >= 0){
        return v1->texto[v1->teto--];
    }
    return '\0';
}

int comparação(char aberto,char fechado){
    return (aberto == '(' && fechado == ')') ||
    (aberto == '[' && fechado == ']') ||
    (aberto == '{' && fechado == '}');
}

int bemFormada(char *texto){
    Vetor vetor;
    iniciar(&vetor);
    for(int i=0;texto[i] !='\0';i++){
        char comparado = texto[i];
        if(comparado == '(' || comparado == '[' || comparado == '{'){
            juntar(&vetor,comparado);
        }else if(comparado == ')' || comparado == ']' || comparado == '}'){
            char topo = separar(&vetor);
            if(!comparação(topo,comparado)){
                return FALSO;   
            }
        }
    }
    return vetor.teto = VERDADEIRO;
}

int main(void){
    char texto[TAM];
    printf("Digite o texto: ");
    scanf("%s",texto);
    if(bemFormada(texto)){
        printf("\nbem formada.");
    }else{
        printf("\nmal formada");
    }
    return 0;
}