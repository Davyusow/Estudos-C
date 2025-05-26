#include "stdio.h"

int main(void) {
  int n1[5];
  int negativos, positivos;
  for (int i = 0; i < 5; i++) {
    printf("Digite o %i° número: ", i+1);
    scanf(" %i", &n1[i]);
    if (n1[i] >= 0) {
        positivos++;
    }else{
        negativos++;
    }
  }
  printf("\nForam digitados %i número(s) positivo(s), e %i negativo(s)\n",positivos,negativos);

  return 0;
}
