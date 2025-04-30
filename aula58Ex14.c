#include "stdio.h"

int main(void){
    int mes;
    printf("Digite o número do mês: ");
    scanf("%i",&mes);
    switch(mes){
        default:
            printf("\nMês inválido!\n");
            break;
        case 1:
            printf("\nJaneiro\n");
            printf("31 dias\n");
            break;
        case 2:
            printf("\nFevereiro\n");
            printf("28 dias\n");
            break;
        case 3:
            printf("\nMarço\n");
            printf("31 dias\n");
            break;
        case 4:
            printf("\nAbril\n");
            printf("30 dias\n");
            break;
        case 5:
            printf("\nMaio\n");
            printf("31 dias\n");
            break;
        case 6:
            printf("\nJunho\n");
            printf("30 dias\n");
            break;
        case 7:
            printf("\nJulho\n");
            printf("31 dias\n");
            break;
        case 8:
            printf("\nAgosto\n");
            printf("31 dias\n");
            break;
        case 9:
            printf("\nSetembro\n");
            printf("30 dias\n");
            break;
        case 10:
            printf("\nOutubro\n");
            printf("31 dias\n");
            break;
        case 11:
            printf("\nNovembro\n");
            printf("30 dias\n");
            break;
        case 12:
            printf("\nDezembro\n");
            printf("31 dias\n");
            break;
    }
}
