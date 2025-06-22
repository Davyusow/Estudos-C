#include "stdio.h"


int main(void){
  int tam = 5,i,j;
  int estrela = 1;


  for(i = 0;i < tam;i++){
    for(j = tam - i;j >= 1 ;j--)
      printf(" ");
    for(j = 0;j <= i;j++)
      printf("*");
    printf("\n");
  }
    


  return 0;
}