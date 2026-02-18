#include "stdio.h"
#include <locale.h>

int main(void) {
  char *valor = setlocale(LC_ALL, ""); // agora fica em português

  printf("Valor: %s\n", valor); // Somente para verificar a localização atual

  return 0;
}
