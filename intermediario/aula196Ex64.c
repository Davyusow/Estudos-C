#include "stdio.h"

void strcpyImprovisado(char* destino, char* origem){
  int i = 0;
  while(origem[i] != '\0'){
    destino[i] = origem[i];
    i++;
  }
  destino[i] = '\0';
}

int main(void){
  char palavra1[100] = "Fulaninho de tal";
  char palavra2[100] = "Ciclaninho de tal";
  
  printf("Palavra1: %s\nPalavra2: %s\n",palavra1,palavra2);
  strcpyImprovisado(palavra1, palavra2);
  printf("Palavra1: %s\nPalavra2: %s\n",palavra1,palavra2);

  return 0;
}