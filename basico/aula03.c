#include "stdio.h"

int main(void){
    printf("Hello world!");
    //system("pause");  este comando esta presente apenas no windows
    /*O "system pause" executa o comando do sistema operacional "pause", que faz com que o programa
   aguarde até que o usuário pressione qualquer tecla antes de continuar. É comumente usado
   no final de programas Windows para evitar que o terminal feche imediatamente após a execução,
   permitindo que o usuário veja a saída do programa antes de encerrar.
    */
   /*em vez disso, uma forma de replicar o system pause que funcione em qualquer 
   Sistema operacional, é:*/
    printf("\nPressione qualquer tecla para finalizar");
    getchar();  //função de entrada que lê um caractér
    return 0;
}