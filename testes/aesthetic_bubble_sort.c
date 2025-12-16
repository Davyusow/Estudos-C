#include <stdio.h>
#include <stdlib.h>

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
  
  
  for (int i = 0;i < 10;i++) {
    for (int j = 0;j < 10;j++) {
      printf("Valor: %d\r",i);
    }
  }
  

  return 0;
}
