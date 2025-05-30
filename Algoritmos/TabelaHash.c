#include "stdio.h"
#include "stdlib.h"

#pragma region //structs
typedef struct cadeia{
    int chave;
    struct cadeia *proximo;
}cadeia;

typedef struct{
    struct cadeia *inicio;
    int tam;
}Lista;
#pragma endregion

#define TAM 31
#pragma region //funções

void inserirNaLista(Lista *l,int valor){
    cadeia *novo = malloc(sizeof(cadeia));
    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }else{
        printf("\nErro ao alocar a memória");
    }
}

int buscarNaLista(Lista *l,int valor){
    cadeia *aux = l->inicio;
    while(aux && aux->chave != valor){
        aux = aux->proximo;
    }if(aux){
        return aux->chave;
    }
    return 0;
}

void imprimirLista(Lista *l){
    cadeia *aux = l->inicio;
    printf(" Tam: %d => ", l->tam);
    while(aux){
        printf("%d -> ", aux->chave);
        aux = aux->proximo;
    }
    printf("NULL");
}

int hash(int chave){
    return chave % TAM;
}

void inserir(Lista t[],int valor){
    int id = hash(valor);
    inserirNaLista(&t[id],valor);
}

int buscar(Lista t[],int chave){
    int id = hash(chave);
    return buscarNaLista(&t[id],chave);
}

void imprimir(Lista *lista){
    for(int i = 0; i < TAM; i++){
    printf("\nIndice %d:", i);
    imprimirLista(&lista[i]);
}
}
#pragma endregion

int main(void){

    int opcao,valor,retorno;
    Lista tabela01[TAM];
    for(int i = 0; i < TAM; i++){
        tabela01[i].inicio = NULL;
        tabela01[i].tam = 0;
    }


    do{
        printf("\n\n Digite 1 para inserir \n Digite 2 para buscar \n Digite 3 para imprimir \n Digite 4 para sair");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("\nQual valor deseja inserir?");
                scanf("%d",&valor);
                inserir(tabela01,valor);
                break;
            break;
            case 2:
                printf("\nQual valor deseja buscar?");
                scanf("%d",&valor);
                retorno = buscar(tabela01,valor);
                if(retorno){
                    printf("O valor encontrado foi %d\n",retorno);
                }else{
                    printf("O valor não foi encontrado\n");
                }
            break;
            case 3:
                imprimir(tabela01);
            break;
            case 4:
                printf("\nSaindo...");
            break;
            default:
                printf("Opcção inválida");
        }
    }while(opcao!=4);

    return 0;
}