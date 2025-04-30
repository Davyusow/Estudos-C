#include "stdio.h"
#include <iso646.h>
#include <stdlib.h>


int main(void) {
  float notas[3];float media = 0;
  for (int i = 0; i < 3; i++) {
    printf("Digite o valor da %i° nota: ",i);
    scanf(" %f",&notas[i]);
    media += notas[i];
  }
  int opcao,condicao = 1;
  while(condicao){
      printf("Digite a opção desejada:\n1\tMédia aritmética\n2\tMédia Ponderada\nOpção(1/2): ");
      scanf(" %i",&opcao);
      switch(opcao){
        default:
            system("clear");
            printf("Opção inválida\n");
            break;
        case 1:
            media /= 3;
            condicao = 0;
            break;
        case 2:
            media = (notas[0]*3 + notas[1]*3 + notas[2]*4)/10;
            condicao = 0;
            break;
      }
  }
  printf("A média foi %.1f\n",media);
}
