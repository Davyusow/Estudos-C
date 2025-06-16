#include "stdio.h"
#include "string.h"
#include "ctype.h"


void minusculo(char string1[],char string2[]){
    int i = 0;
    while(string1[i] != '\0'){
        string2[i] = toupper(string1[i]);
        i++;
    }
}

int main(void){
    //strupr(); // só funciona no windows com mingw
    char str1[] = "TextinHo HoRrEnDO" ;
    char str2[40];
    minusculo(str1,str2);

    printf("%s \n",str2);
    
    return 0;
}