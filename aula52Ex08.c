#include "stdio.h"

int main(void){
    int n1,n2,n3;
    printf("Digite o 1° número: ");
    scanf("%i",&n1);
    printf("Digite o 2° número: ");
    scanf(" %i",&n2);
    printf("Digite o 3° número: ");
    scanf(" %i",&n3);

    if(n1 >= n2 && n1>=n3){
        printf("\n%i é o maior número!\n",n1);
    }else if(n2 >= n1 && n2>=n3){
        printf("\n%i é o maior número!\n",n2);
    }else if(n3 >= n2 && n3>=n2){
        printf("\n%i é o maior número!\n",n3);
    }else{
        printf("\nTodos os números são iguais\n");
    }

    if(n1 <= n2 && n1 <= n3){
        printf("\n%i é o menor número!\n",n1);
    }else if(n2 <= n1 && n2 <= n3){
        printf("\n%i é o menor número!\n",n2);
    }else if(n3 <= n2 && n3 <= n2){
        printf("\n%i é o menor número!\n",n3);
    }

    return 0;
}
