#include "stdio.h"

int main(){
    int idade;


    int num1[10];
    int num2[] = {1,5,9,15,43};
    for(int i = 0;i<5;i++){
        printf("%d ",num2[i]);
    }
    printf("\n");

    int num5[5] = {0}; // [0,0,0,0,0]
    char vogais[5] = {'a','e','i','o','u'};
    for(int i = 0;i<5;i++){
        printf("%c ",vogais[i]);
    }
    printf("\n");
    return 0;
}
