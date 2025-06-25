#include "stdio.h"

int main(void){
  char palavra[100];
  scanf("%s100[^\n]",palavra);
  //o scanf de strings não pedia o endereço de memória, 
  printf("%s\n",palavra);

  printf("%p\n", palavra);
  printf("%p\n", &palavra);
  printf("%p\n", &palavra[0]);  //os 3 endereços são iguais
  //o vetor por si só é um ponteiro
  //o string aponta para o início do vetor, quando impresso com %s imprime toda a string
  //E todo ponteiro é equivalente à um vetor, se estiver apontando apenas para um valor,
  //é inteiramente igual à p[0] por exemplo

  return 0;
}