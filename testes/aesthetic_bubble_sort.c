#include <stdio.h>

#define TAM 10

// typedef struct Objeto {
//   int quantidade
//   char* nome;
// };

// typedef struct Lista {
//   Objeto[] dados;
// }

int main(void){

  // Lista lista = malloc(sizeof(*Objeto)*TAM)
  printf("Tudo certo até aqui?\n");

  int dados[10] = {2,5,2,5,7,43,7,9,3,1};
  int resultado[10];
  for (int i = 0;i < 10;i++) {
    for (int j = 0;j < 10;j++) {
      if (dados[i] > dados[i+1]) {
        int temp = dados[i];
        dados[i+1] =
        dados[i] = dados[i+1];
      }
      printf("Valor: %d\r",i);
    }
  }


  return 0;
}
