#include "stdio.h"
#include "stdlib.h"

//contantes lógicos
#define TRUE 1
#define FALSE 0
#define NAO_ENCONTRADO -1
#define NIL -1

//constantes do menu
#define VER 1
#define INSERIR 2
#define BUSCAR 3
#define EXCLUIR 4
#define SAIR 0

typedef struct {
  int chave;    //é o valor armazenado na lista
} Registro;

typedef struct {
  int maximo;    // vai armazenar o tamanho da lista
  int ultimo;    // vai armazenar o último índice onde o valor foi adicionado
  Registro* Dados; // é o vetor dos dados, o +1 é essencial para o busca sentinela
} ListaSequencial;

int buscaSequencial(ListaSequencial *lista, int chave){
  int indice = 0;
  while(indice < lista->ultimo){
    if(chave == lista->Dados[indice].chave)
      return indice;
    else indice++;
  }
  return NAO_ENCONTRADO;
}

void insercaoSequencial(ListaSequencial *lista,int chave){
    if(lista->ultimo < lista->maximo){
    if(buscaSequencial(lista, chave) == NAO_ENCONTRADO){
        lista->Dados[lista->ultimo].chave = chave;
        lista->ultimo++;
        printf("Valor inserido com sucesso!\n");

        }else{
            printf("O elemento %i já existe na lista!\n",chave);
        }
    }else
        printf("Lista cheia!\n");
}

int excluir(ListaSequencial *lista,int chave){
  int indice;  
  int posicao = buscaSequencial(lista, chave);  
  if(posicao == NAO_ENCONTRADO) return FALSE;
  for(indice = posicao; indice < lista->ultimo-1;indice++)
      lista->Dados[indice] = lista->Dados[indice+1];
  lista->ultimo--;
  return TRUE;
}

void imprimeVetor(ListaSequencial lista) { 
  printf("[ ");
  for (int i = 0; i < lista.maximo; i++) {
    if(i < lista.ultimo)
      printf("%i ", lista.Dados[i].chave);
    else  
      printf("NIL ");
  }
  printf("]\n");
}

void reiniciarVetor(ListaSequencial *lista) {         
  for (int y = 0; y < lista->maximo; y++)
    lista->Dados[y].chave = NIL;
  lista->ultimo = 0;
}

int lerInteiro(char *mensagem) {
  int valorLido;
  printf("%s", mensagem);
  while (scanf(" %d", &valorLido) != TRUE) {
    while (getchar() != '\n');
    printf("%s", mensagem);
  }
  return valorLido;
}

ListaSequencial dobraVetor(ListaSequencial *lista){
  ListaSequencial novaLista;
  novaLista.maximo = lista->maximo * 2;
  novaLista.Dados = (Registro*) malloc(sizeof(Registro) * novaLista.maximo);
  for(int i = 0; i < lista->ultimo; i++) {
    novaLista.Dados[i] = lista->Dados[i];
  }
  novaLista.ultimo = lista->ultimo;
  return novaLista;
}

int main(void){

ListaSequencial listaSequencial;
int opcao,tamanho;

printf("Primeiramente, insira o tamanho(inteiro maior que 0) desejado para o vetor.\n");

do{
tamanho = lerInteiro("Tamanho: ");
}while(tamanho < 1);

listaSequencial.Dados = (Registro*) malloc(sizeof(Registro)*tamanho);
listaSequencial.maximo = tamanho;
reiniciarVetor(&listaSequencial);

do{
  int tempChave = -1;
printf("---------------------------------------"
              "\n\tLista Linear Sequencial\n"
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
      imprimeVetor(listaSequencial);
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      if(listaSequencial.ultimo == listaSequencial.maximo){
        printf("Limite alcançado!\nDobrando o vetor...\n");
        listaSequencial = dobraVetor(&listaSequencial);
      }
        tempChave = lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
        insercaoSequencial( &listaSequencial,  tempChave);
      
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      int tempBusca = buscaSequencial(&listaSequencial, tempChave);
      if(tempBusca != NAO_ENCONTRADO)
        printf("O valor %i foi encontrado no índice %i.\n",tempChave,tempBusca);
      else
        printf("%i não esta presente no vetor.\n",tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da lista: ");
      tempBusca = buscaSequencial(&listaSequencial, tempChave);
      if(excluir(&listaSequencial, tempChave))
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
  free(listaSequencial.Dados);
  return 0;
}
