#include "stdio.h"

int main(void) {
int I = 1; int J = 7;

for(int contador = 0;contador<5;contador++){
    for(int rodada = 0;rodada < 3;rodada++){
        printf("I=%d J=%d\n",I,J);
        J--;
    }
    I+=2;
    J+=5;
}


  return 0;
}
