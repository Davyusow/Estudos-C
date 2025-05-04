#include "stdio.h"
#define DIAS_LIMITES 30

int main(void) {
 float saldo = 0;
  for (int dias = 1; dias <= DIAS_LIMITES; dias++) {
      saldo += 0.02;
      printf("Saldo no dia %d : %.2f\n",dias,saldo);
  }

  return 0;
}
