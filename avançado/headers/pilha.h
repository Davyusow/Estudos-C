#ifndef PILHA_H_INCLUDED    //abre um if para o cabeçalho
//se pilha.h não estiver definida
#define PILHA_H_INCLUDED //define o cabeçalho

// o cabeçalho apenas inclue as assinaturas dos métodos e structs
// lembra as interfaces de java

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No *empilhar(No *pilha,int num);

No* desempilhar(No **pilha);

void imprimir(No *pilha);

#endif //fim do if
