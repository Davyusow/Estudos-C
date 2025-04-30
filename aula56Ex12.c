#include "stdio.h"

int main(void){
    float altura,peso;
    printf("Digite seu peso(kg): ");
    scanf("%f",&peso);
    printf("Digite sua altura(m): ");
    scanf(" %f",&altura);

    float imc = altura/(peso*peso);

    if(imc < 18.5 ){
        printf("Abaixo do peso\n");
    }else if(18.5 <= imc && imc < 25){
        printf("Peso normal\n");
    }else if(25 <=imc && imc < 30){
        printf("Sobre peso\n");
    }else if(30 <= imc && imc < 35){
        printf("Obesidade grau 1\n");
    }else if(35 <= imc && imc < 40){
        printf("Obesidade grau 2\n");
    }else if(imc >=40){
        printf("Obesidade grau 3\n");
    }

    return 0;
}
