#include "stdio.h"

int main(void){
    float lados[3];
    printf("Digite os três lados de um triângulo: \n");
    for(int i = 0;i<3; i++){
        scanf("%f",&lados[i]);
    }

    if(lados[0] + lados[1] < lados[2] || lados[2] + lados[1] < lados[0] || lados[0] + lados[2] < lados[1] ){
        printf("\nO triângulo é impossível!\n");
    }else if(lados[0] == lados[1] && lados[0] == lados[2] ){
        printf("\nTriângulo equilátero!\n");
    }else if(lados[0] != lados[1] && lados[0] != lados[2] && lados[1] != lados[2] ){
        printf("\nTriângulo Escaleno!\n");
    }else if(lados[0] == lados[1] || lados[0] == lados[2] || lados[1] == lados[2] ){
        printf("\nTriângulo Isóceles!\n");
    }

    return 0;
}
