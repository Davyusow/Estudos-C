#include "stdio.h"

int main(void){
    int opcao;
    printf("Insira a opção que deseja: \n");
    printf("- 1 \tCadastrar Produto\n");
    printf("- 2 \tVender Produto\n");
    printf("- 3 \tBuscar Produto\n");
    printf("- 4 \tImprimir Produto\n");
    printf("- 5 \tSair\nopcao: ");
    scanf("%i",&opcao);
    
    switch(opcao){
        default:
            printf("\nOpção inválida! Insira um valor entre 1 e 5!\n");
        break;
        case 1:
            printf("\nCadastro selecionado\n");
            break;
        case 2:
            printf("\nVenda selecionada\n");
            break;
        case 3:
            printf("\nBusca selecionada\n");
            break;
        case 4:
            printf("\nImpressão selecionada\n");
            break;
        case 5:
            printf("\nSaindo...\n");
            break;
    }

    return 0;
}
