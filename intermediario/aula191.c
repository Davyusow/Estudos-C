#include "stdio.h"

int main(void){
  int A = 100, *B, **C;
  //C é um ponteiro para ponteiro, C -> B -> A
  B = &A;
  C = &B;

  printf("Endereço de A: %p\nConteúdo de A: %i\n", &A, A);
  printf("Endereço de B: %p\nConteúdo de B: %i\n", &B, *B);
  printf("Endereço de C: %p\nConteúdo de C: %i\n", &C, **C);
  return 0;
}