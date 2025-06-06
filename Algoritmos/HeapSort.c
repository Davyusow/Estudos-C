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
#define ORDENAR 5
#define SAIR 0

typedef struct Vetor { 
    int *dados;
    int ultimo;
    int tamanho;
}Vetor;


int totalTrocas = 0;
int totalMaxHeapify = 0;

void imprimeVetor(Vetor vetor) { 
  printf("[ ");
  for (int i = 0; i < vetor.ultimo; i++) {
      printf("%i ", vetor.dados[i]);
  }
  printf("]\n");
}

void maxHeapify(Vetor* vetor,int indice,int tamanho){
    totalMaxHeapify++;

    int esquerda = 2*indice+1;
    int direita = 2*indice+2;
    int maior;
    if(esquerda < tamanho && vetor->dados[esquerda] > vetor->dados[indice])
        maior = esquerda;
    else
        maior = indice;
    if(direita < tamanho && vetor->dados[direita] > vetor->dados[maior])
        maior = direita;
    if(maior != indice){
        int temp = vetor->dados[indice];
        vetor->dados[indice] = vetor->dados[maior];
        vetor->dados[maior] = temp;
        totalTrocas++;

        printf("\nApós o maxHeapify (indice %d)",indice);
        imprimeVetor(*vetor);

        maxHeapify(vetor,maior,tamanho);
    }
}

void construirHeap(Vetor* vetor,int tamanho){
    for(int indice = tamanho/2 -1; indice >= 0 ; indice--){
        maxHeapify(vetor,indice,tamanho);
    }
    printf("Vetor após construir o heap: ");
    imprimeVetor(*vetor);
}

void heapSort(Vetor* vetor,int tamanho){
    totalTrocas = 0;
    totalMaxHeapify = 0;
    construirHeap(vetor,tamanho);
    for(int indice = tamanho-1; indice > 0 ;indice--){
        int temp = vetor->dados[0];
        vetor->dados[0] = vetor->dados[indice];
        vetor->dados[indice] = temp;
        totalTrocas++;
        printf("Após troca no heapSort: ");
        imprimeVetor(*vetor);

        maxHeapify(vetor, 0, indice);
    }
}

int buscaSequencial(Vetor* vetor, int chave){
  int indice = 0;
  while(indice < vetor->ultimo){
    if(chave == vetor->dados[indice])
      return indice;
    else indice++;
  }
  return NAO_ENCONTRADO;
}

void insercaoSequencial(Vetor* vetor,int chave){
  if(vetor->ultimo < vetor->tamanho){
    if(buscaSequencial(vetor, chave) == NAO_ENCONTRADO){            
      vetor->dados[vetor->ultimo] = chave;
        vetor->ultimo++;
        printf("Valor inserido com sucesso!\n");
    }
    else{
        printf("O elemento %i já existe na lista!\n",chave);
    }
  }
  else{
    printf("Vetor Cheio!\n");
  }
}

int excluir(Vetor* vetor,int chave){
  int indice;  
  int posicao = buscaSequencial(vetor, chave);  
  if(posicao == NAO_ENCONTRADO) return FALSE;
  for(indice = posicao; indice < vetor->ultimo-1;indice++)
    vetor->dados[indice] = vetor->dados[indice+1];
  --vetor->ultimo;
  return TRUE;
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


int main(void){
Vetor vetor;
int opcao,tempChave = NAO_ENCONTRADO;
vetor.dados = (int *) malloc(sizeof(int)*1);
vetor.tamanho = 1;
vetor.ultimo = 0;

do{
printf("----------------------------------------"
              "\n Lista Linear Sequencial Com HeapSort\n"
              "----------------------------------------\n");
  printf(" Digite um número para escolher a opção:  \n"
        " 1 ⟶ Para Imprimir o vetor\n"
        " 2 ⟶ Para inserir um valor\n"
        " 3 ⟶ Para buscar um valor\n"
        " 4 ⟶ Para excluir um valor\n"
        " 5 ⟶ Para Ordenar o vetor (HeapSort)\n"
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
      imprimeVetor(vetor);
      break;
    case INSERIR:
      system("clear");
      printf("Inserindo...\n");
      vetor.dados = (int *) realloc(vetor.dados, sizeof(int) * (vetor.tamanho + 1));
      ++vetor.tamanho;
      tempChave = lerInteiro("Insira aqui o valor da chave que deseja inserir: ");
      insercaoSequencial(&vetor,  tempChave);
      break;
    case BUSCAR:
      system("clear");
      printf("Buscando...\n");
      tempChave = lerInteiro("Digite o valor que deseja buscar: ");
      int tempBusca = buscaSequencial(&vetor, tempChave);
      if(tempBusca != NAO_ENCONTRADO)
        printf("O valor %i foi encontrado no índice %i.\n",tempChave,tempBusca);
      else
        printf("%i não esta presente no vetor.\n",tempChave);
      break;
    case EXCLUIR:
      system("clear");
      printf("Excluindo...\n");
      tempChave = lerInteiro("Digite o valor que deseja remover da lista: ");
      tempBusca = buscaSequencial(&vetor, tempChave);
      if(excluir(&vetor, tempChave)){
        printf("%i removido com sucesso!\n",tempChave);
      }
      else
        printf("O valor %i não foi encontrado no vetor.\n",tempChave);
      break;
    case ORDENAR:
      system("clear");
      printf("Ordenando...\n");
      heapSort(&vetor, vetor.ultimo);
      printf("\nHeapSort completo: ");
      printf("\nEstatísticas do HeapSort:\n");
      printf("Total de trocas realizadas: %d\n", totalTrocas);
      printf("Total de chamadas a maxHeapify: %d\n", totalMaxHeapify);
      imprimeVetor(vetor);
      break;
    case SAIR:
      system("clear");
      printf("Saindo...\n");
      break;
  }

}while(opcao != SAIR);
  printf("Até logo!");
  free(vetor.dados);
  return 0;
}
