#include "stdio.h"

int main(void){
float alturaChico = 1.50,alturaZe = 1.10;
int anos = 0;

while(alturaChico>alturaZe){
    alturaChico+=0.02;
    alturaZe+=0.03;
    anos++;
}
printf("Precisariam de %d anos para zé ficar mais alto que chico\n",anos);

    return 0;
}
