#include "stdio.h"
#include "ctype.h"

int main(void){
    char textoMalFormatado[38] = "Um TexTo HorRoSo dE Se Ler MinhA nOSSA";

    for(int i = 0 ;i < 38;i++){
        textoMalFormatado[i] = toupper(textoMalFormatado[i]);
    }
    printf("%s\n",textoMalFormatado);
    for(int i = 0 ;i < 38;i++){
        textoMalFormatado[i] =  tolower(textoMalFormatado[i]);
    }
    printf("%s\n",textoMalFormatado);
    return 0;
}
