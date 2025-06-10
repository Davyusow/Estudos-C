#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void){
    srand(time(NULL));
    int matriz[3][3];

    for(int i= 0;i<3;i++){
        for(int j=0;j<3;j++)
            matriz[i][j] = rand() % 101;
    }

    for(int i= 0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("valor : %3i, ",matriz[i][j]);
        }
        printf("\n");
    }
}
