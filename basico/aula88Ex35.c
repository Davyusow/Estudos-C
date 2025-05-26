#include "stdio.h"
int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != 1) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

int main(void){
int vertical,horizontal;

do{
    horizontal = lerInteiro("Digite a posição da coordanada X: ");
    vertical = lerInteiro("Digite a posição da coordanada Y: ");
    if( horizontal > 0 && vertical > 0)
        printf("Primeiro quadrante\n");
    else if( horizontal < 0 && vertical > 0)
        printf("Segundo quadrante\n");
    else if( horizontal < 0 && vertical < 0)
        printf("Terceiro quadrante\n");
    else if( horizontal > 0 && vertical < 0)
        printf("Quarto quadrante\n");
}while(horizontal != 0 && vertical !=0);

    return 0;
}
