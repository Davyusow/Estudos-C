#include "stdio.h"

int main(void){
    char opcao;
    printf("Insira a opção que deseja: \n");
    printf("- a \tCadastrar Produto\n");
    printf("- b \tVender Produto\n");
    printf("- c \tBuscar Produto\n");
    printf("- d \tImprimir Produto\n");
    printf("- e \tSair\nopcao: ");
    scanf("%c",&opcao);


    switch(opcao){
        default:
            printf("\nOpção inválida! Insira um valor entre 1 e 5!\n");
        break;
        case 'a':
            printf("\nCadastro selecionado\n");
            break;
        case 'b':
            printf("\nVenda selecionada\n");
            break;
        case 'c':
            printf("\nBusca selecionada\n");
            break;
        case 'd':
            printf("\nImpressão selecionada\n");
            break;
        case 'e':
            printf("\nSaindo...\n");
            break;
    }

    return 0;
}
