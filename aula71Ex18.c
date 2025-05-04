#include "stdio.h"

int main(void) {
  int senha = 123456;
  int tentativa;

  printf("Digite a sua senha: ");
  scanf("%i",&tentativa);

  while (tentativa != senha){
    printf("Senha inválida: ");
    scanf("%i",&tentativa);
  }
printf("Acesso permitido!");

return 0;
}
