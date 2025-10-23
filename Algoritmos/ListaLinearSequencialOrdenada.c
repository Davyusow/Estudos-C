#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

//contantes lógicos
#define NAO_ENCONTRADO -1
#define NIL -1

//constantes do menu
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define SAIR 0

typedef struct Registro{
  int chave;
} Registro;

typedef struct ListaSequencialOrdenada{
  int maximo;
  int ultimo;
  Registro* Dados;
} ListaSequencialOrdenada;

int buscaBinaria(ListaSequencialOrdenada *lista, int chave){
  int esquerda,direita,meio;
  esquerda = 0;
  direita = lista->ultimo-1;
  while(esquerda <= direita){
    meio = ((esquerda + direita) / 2);
    if(lista->Dados[meio].chave == chave) return meio;
    else if(lista->Dados[meio].chave < chave)
      esquerda = meio + 1;
    else
      direita = meio - 1;
  }
  return NIL;
}

int exclusaoElementos(ListaSequencialOrdenada *lista, int chave){
  int posicao, contador;
  posicao = buscaBinaria(lista,chave);
  if(posicao == -1) return 0;
  for(contador = posicao;contador<lista->ultimo-1;contador++)
    lista->Dados[contador] = lista->Dados[contador+1];
  lista->ultimo--;
  return 1;
}

int insercaoOrdenada(ListaSequencialOrdenada *lista,int chave){
    if(lista->ultimo == lista->maximo) return 0;
    int posicao = lista->ultimo;
    while(posicao > 0 && lista->Dados[posicao-1].chave > chave){
        lista->Dados[posicao] = lista->Dados[posicao-1];
        posicao--;
    }
    lista->Dados[posicao].chave = chave;
    lista->ultimo++;
    return 1;
}

void imprimeVetor(ListaSequencialOrdenada lista) {
  printf("[ ");
  for (int i = 0; i < lista.maximo; i++) {
    if(i < lista.ultimo)
      printf("%i ", lista.Dados[i].chave);
    else
      printf("NIL ");
  }
  printf("]\n");
}


void reiniciarVetor(ListaSequencialOrdenada *lista) {
  for (int y = 0; y < lista->maximo; y++)
    lista->Dados[y].chave = NIL;
  lista->ultimo = 0;
}

ListaSequencialOrdenada dobraVetor(ListaSequencialOrdenada *lista){
  ListaSequencialOrdenada novaLista;
  novaLista.maximo = lista->maximo * 2;
  novaLista.Dados = (Registro*) malloc(sizeof(Registro) * novaLista.maximo);
  for(int i = 0; i < lista->ultimo; i++) {
    novaLista.Dados[i] = lista->Dados[i];
  }
  novaLista.ultimo = lista->ultimo;
  return novaLista;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != true) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}


int main(void){

ListaSequencialOrdenada listaOrdenada;
int opcao,tamanho;

printf("Primeiramente, insira o tamanho(inteiro maior que 0) desejado para o vetor.\n");

do{
tamanho = lerInteiro("Tamanho: ");
}while(tamanho < 1);

listaOrdenada.Dados = (Registro*) malloc(sizeof(Registro)*tamanho);
listaOrdenada.maximo = tamanho;
reiniciarVetor(&listaOrdenada);

do{
  int tempChave = -1;
printf("---------------------------------------"
              "\nLista Linear Sequencial Ordenada\n"
              "---------------------------------------\n");
  printf(" Digite um número para escolher a opção:  \n"
        " 1 ⟶ Para Imprimir o vetor\n"
        " 2 ⟶ Para inserir um valor\n"
        " 3 ⟶ Para buscar um valor\n"
        " 4 ⟶ Para excluir um valor\n"
        " 0 ⟶ Para sair\n");
        opcao = lerInteiro("Opção: ");

  switch(opcao){
    default:
      system("clear");
      printf("Opção inválida!\n");
      break;
    case VER:
      system("clear");
      printf("Imprimindo...\n");
      imprimeVetor(listaOrdenada);
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      if(!insercaoOrdenada(&listaOrdenada, lerInteiro("Insira um valor inteiro: "))){
        printf("Limite alcançado!\n");
        imprimeVetor(listaOrdenada);
        printf("Dobrando vetor...\n");
        listaOrdenada = dobraVetor(&listaOrdenada);
        imprimeVetor(listaOrdenada);
        printf("Por favor, reinsira o valor desejado!\n");
      }
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      int tempBusca = buscaBinaria(&listaOrdenada, tempChave);
      if(tempBusca != NAO_ENCONTRADO)
        printf("O valor %i foi encontrado no índice %i.\n",tempChave,tempBusca);
      else
        printf("%i não esta presente no vetor.\n",tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da lista: ");
      tempBusca = buscaBinaria(&listaOrdenada, tempChave);
      if(exclusaoElementos(&listaOrdenada, tempChave))
        printf("%i removido com sucesso!\n",tempChave);
      else
        printf("O valor %i não foi encontrado no vetor.\n",tempChave);
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
  }

}while(opcao != SAIR);
  printf("Até logo!");
  free(listaOrdenada.Dados);
  return 0;
}
