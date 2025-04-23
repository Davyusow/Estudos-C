#include "stdio.h"

int main(void){
    unsigned int segundos,minutos,horas;
    printf("Insira o tempo em segundos: ");
    scanf("%i",&segundos);
    horas = (int)(segundos / 3600);
    segundos -= horas*3600;
    minutos = (int)(segundos / 60);
    segundos -= minutos*60;

    printf("%i:%i:%i\n",horas,minutos,segundos);

    return 0;
}