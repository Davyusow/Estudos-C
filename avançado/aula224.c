#include "stdio.h"
#include "stdlib.h"

#define TAM 50

#define TRUE 1
#define FALSE 0

#define EMPILHAR 1
#define DESEMPILHAR 2
#define IMPRIMIR 3
#define SAIR 0

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[TAM];
    Data data;
}Pessoa;

typedef struct No{
    Pessoa pessoa;
    struct No *proximo;
}No;

Pessoa lerPessoa(){
    Pessoa pessoa;
    printf("Digite um nome: ");
    fgets(pessoa.nome, TAM, stdin);
    printf("Digite a data de aniversário dd/mm/aaaa: ");
    scanf(" %i/%i/%i",&pessoa.data.dia,&pessoa.data.mes,&pessoa.data.ano);
    return pessoa;
}

void imprimirPessoa(Pessoa pessoa){
    printf("\nNome: %sData de aniversário: %2i/%2i/%4i\n",pessoa.nome,pessoa.data.dia,pessoa.data.mes,pessoa.data.ano);
}

int lerInteiro(char *mensagem){
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE){
    while (getchar() != '\n')
        printf("%s", mensagem);
  }
  return valorLido;
}

// algoritmo da pilha (push)

No* empilhar(No *topo){ //push
    No *novo = malloc(sizeof(No));
    if(novo){ //se for alocada corretamente
        novo->pessoa = lerPessoa();
        novo->proximo = topo;
        return novo;
    }else
        printf("Erro ao alocar memória!\n");
    return NULL;
}

No* desempilhar(No **topo){ //pop
    if(*topo != NULL){
        No* remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else
        printf("Pilha vazia\n");
    return NULL;
}

void imprimirPilha(No *topo){
    printf("-------------------------\n");
    while(topo != NULL){
        imprimirPessoa(topo->pessoa);
        topo = topo->proximo;
    }
    printf("-------------------------\n");
}

int main(void){

    No *pilha = NULL; //aponta para o topo da pilha
    No *remover;
    int opcao;

    do{
        printf("Digite a opção que deseja: \n"
            "1 -> Empilhar\n"
            "2 -> Desempilhar\n"
            "3 -> Imprimir\n"
            "0 -> Sair\n");
        switch (opcao = lerInteiro("Digite sua opção: ")) {
            case EMPILHAR:
                getchar();
                pilha = empilhar(pilha);
            break;
            case DESEMPILHAR:
                if((remover = desempilhar(&pilha)) != NULL){
                    printf("Removendo: \n");
                    imprimirPessoa(remover->pessoa);
                    free(remover);
                }else
                    printf("Sem nó para remover\n");
            break;
            case IMPRIMIR:
                imprimirPilha(pilha);
            break;
            case SAIR:
                printf("\nAté logo!");
            break;
            default:
                printf("\n<opção inválida>");
            break;
        }
    }while(opcao != SAIR);
    free(pilha);
    return 0;
}
