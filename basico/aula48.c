#include "stdio.h"

int main(void){
    int idade;
    printf("Insisira sua idade: ");
    scanf("%i",&idade);
    if(idade <= 5 || idade >=60){      //'||'se a primeira, segunda ou todas as operações lógicas forem verdadeiras
        printf("Tem direito a gratuidades!");
    }else{
        printf("Não tem direito a gratuidades!");
    }

    return 0;
}