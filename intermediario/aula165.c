#include "stdio.h"
#include "time.h"
#include <time.h>

int fibonnaciRecursivo(int num){
    if(num == 1)
        return 0;
    else{
        if(num == 2)
            return 1;
        else
            return fibonnaciRecursivo(num-1) + fibonnaciRecursivo(num-2);
    }
}

int fibonnaciIterativo(int num){
    int n1 = 0, n2 = 1, n3, indice = 2;
    if(num == 1)
        return n1;
    else{
        if(num == 2)
            return n2;
        else{
            while(indice < num){
                n3 = n1 + n2;
                n1 = n2;
                n2 = n3;
                indice++;
            }
            return n3;
        }
    }
}

int main(void){
    int numero = 50;
    time_t tempoInicio, tempoFim;

    tempoInicio = time(NULL);
    printf("Fibonnaci iterativo %d\n",fibonnaciIterativo(numero));
    tempoFim = time(NULL);

    printf("\tTempo: %f\n", difftime(tempoFim, tempoInicio)); // com numero = 45, instântaneo
    //com numero = 50, instântaneo
    tempoInicio = time(NULL);
    printf("Fibonnaci recursivo %d\n",fibonnaciRecursivo(numero));
    tempoFim = time(NULL);

    printf("\tTempo: %f\n", difftime(tempoFim, tempoInicio)); //com numero = 45,  levou 6 segundos
    //com numero = 50, 67 segundos

    //portanto uma função recursiva é mais lenta que uma função interativa

    return 0;
}
