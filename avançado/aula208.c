#include "stdio.h"

int main(void){

    FILE *arquivo; //ponteiro para o arquivo
    char letra;

    // O primeiro parâmetro é o nome do arquivo, pode ser passado o caminho do arquivo
    // ou então apenas o nome caso ele esteja na mesma pasta
    // O segundo parâmetro é o modo de abertura do arquivo
    // as siglas são semelhantes às permissões de arquivo no linux
    //
    // r -> leitura
    // w -> escrita
    // a -> append/ concatena/ adiciona
    // r+ -> leitura e escrita
    // w+ -> leitura e escrita (substitui o arquivo original)
    // a+ -> leitura e escrita (adiciona no fim do arquivo)
    arquivo = fopen("texto.txt","w"); //abre um arquivo no modo leitura
    //se o arquivo não existir no modo escrita ele é criado
    if(arquivo == NULL){
        printf("Arquivo não existe!");
        return 1;
    }
    else{
        printf("Digite um texto e pressione enter ao finalizar: ");
        scanf("%c", &letra);
        while (letra != '\n') { //enquanto o enter não for pressionado:
            fputc(letra,arquivo);
            //adiciona um caracter no arquivo
            scanf("%c", &letra);
            //vai ler o próximo caracter no buffer do teclado
        }
    }
    fclose(arquivo); //fecha o arquivo de maneira segura
    return 0;
}
