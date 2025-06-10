#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void){
    srand(time(NULL));  //configura o seed do rand para criar números aleátorios apartir do horário do co>
    int contador;
    int valores[10];

    for(contador = 0;contador<10;contador++)
        valores[contador] = rand() % 100; //limita a atribuição para 99

    printf("\n");
    for(contador = 0;contador<10;contador++){
        printf("Valor : %i\n",valores[contador]);
    }

    return 0;
}
