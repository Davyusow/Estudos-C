#include "stdio.h"

void troca(float *a, float *b){
  float temp = *a;
  *a = *b;
  *b = temp;
}

int main(void){
  float num1 = 5.2, num2 = 3.2;
  printf("num1: %f\nnum2: %f\n",num1,num2);
  troca(&num1,&num2);
  printf("\nApós a troca\n\nnum1: %f\nnum2: %f\n",num1,num2);
  return 0;
}