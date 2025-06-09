#include "stdio.h"
#include "string.h"

int main(void){
    char nome[40] = "Dayvson";
    char sobrenome[20] = " Farias";
    strcat(nome,sobrenome); //concatena(junta) nome + sobrenome
    printf("%s",nome);
    return 0;
}
