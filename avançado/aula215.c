#include "stdio.h"
#include "stdlib.h"

//constantes lógicas
#define TAM 50
#define TRUE 1
#define FALSE 0
//constantes do menu
#define CADASTRAR 1
#define EDITAR 2
#define IMPRIMIR 3
#define SALVAR 4
#define CARREGAR 5
#define SAIR 0

typedef struct Contato{
    char nome[TAM];
    int dia, mes, ano;
}Contato;

void imprimir(Contato **contato,int quant){ //ponteiro para ponteiro pois a agenda é um array e ponteiro (dois *)
    printf("\nLista de Contatos: \n\n");
    for(int indice = 0;indice < quant; indice++){
        printf("id: %i = %2i/%2i/%4i  %s",indice + 1,
            contato[indice]->dia, contato[indice]->mes, contato[indice]->ano, contato[indice]->nome);
    }
}

int cadastrarContato(Contato **contato, int quant){
    if(quant < TAM){
        Contato *novo = malloc(sizeof(Contato));
        printf("Digite seu nome: ");
        fgets(novo->nome,sizeof(char) * 50,stdin);

        printf("Digite a data de nascimento: dd/mm/aaaa: ");
        scanf(" %i/%i/%i",&novo->dia,&novo->mes,&novo->ano);
        contato[quant] = novo;
        return TRUE;
    }else{
        printf("\nImpossível cadastrar, vetor cheito!\n");
        return FALSE;
    }
}

void aleterarContato(Contato **contato, int quant){
    imprimir(contato, quant);
    int id;
    printf("\nDigite o id do contato que deseja alterar: ");
    scanf(" %i",&id); id--;
    getchar();

    if(id >= 0 && id < quant){
        cadastrarContato(contato, id);
    }else{
        printf("\nid inválido!");
    }
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

int main(void){
    Contato *agenda[TAM];
    int quantidade = 0, opcao = 0;
    do{
        printf("\nDigite a opção desejada:\n"
            "1 -> Cadastrar\n"
            "2 -> Editar\n"
            "3 -> Imprimir\n"
            "0 -> Sair\n");
        opcao = lerInteiro("Opção: ");
        getchar();
        switch(opcao){
            default:
                printf("\nOpção inválida!");
            break;
            case CADASTRAR:
                quantidade += cadastrarContato(agenda, quantidade);
            break;
            case EDITAR:
                aleterarContato(agenda, quantidade);
            break;
            case IMPRIMIR:
                imprimir(agenda, quantidade);
            break;
            case SAIR:
                printf("\nAté logo!\n");
            break;
        }
    }while(opcao != 0);

    free(*agenda);
    return 0;
}
