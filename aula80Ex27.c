#include "stdio.h"

void calculaTempo(unsigned int segundos){
    unsigned int minutos,horas;
    horas = (int)(segundos / 3600);
    segundos -= horas*3600;
    minutos = (int)(segundos / 60);
    segundos -= minutos*60;
    printf("Tempo necessário: %i:%i:%i\n",horas,minutos,segundos);
}

int main(void){
    float massa;
    unsigned int tempo = 0;
    do{
        printf("Digite o peso do material(g): \n");
        scanf(" %f",&massa);
    }while(massa <= 0.05);

    while(massa > 0.05){
        printf("Massa com %d segundos: %.2f\n",tempo,massa);
        massa/=2;
        tempo+=50;
    }
    calculaTempo(tempo);

    return 0;
}
