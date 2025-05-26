#include "stdio.h"

int main(void) {
  int primos[7] = {2, 3, 5, 7, 11, 13, 17};
  int contador = 6, mmc = 1;
  int max = 10, min = 1;

  printf("MMC entre 10 e 1: \n");

  while (contador >= 0) {   //funcionou mas se o número primo puder dividir os 2 vai dar errado
    if (max % primos[contador] == 0){
      max = max / primos[contador];
      mmc *= primos[contador];
    }else if (min % primos[contador] == 0){
      min = min / primos[contador];
      mmc *= primos[contador];
    }else
      contador--;
  }

  printf("O mmc de 1 e 10 é: %d\n", mmc);

  return 0;
}
