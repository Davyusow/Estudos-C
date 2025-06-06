# Algoritmos
Este readme é dedicado à anotações a respeito de algoritmos e estrutura de dados

<details> <summary> <h1>Insertion Sort</h1> </summary>

É um algoritmo de ordanação por **inserção**, daí o nome, feito apartir de um array  
que constroe uma matriz com um elemento por vez. Uma analogia com o mundo real é o
embaralhamento de cartas.

- Características 
1. Fácil implementação e manuntenção
2. Requer quantidade constante de memória
3. É estável
4. Bom para trabalhar com pequenas entradas  
e arrays quase completamente ordenados

## Pseudocódigo

```
procedimento insertionSort(vetor[], tamanho){
  i,j,chave
	para i = 1 até tamanho-1 passo 1{
      chave = vetor[i];
      j = i - 1;
      enquanto(j>=0 && vetor[j]>chave){
      	vetor[j + 1] = vetor[j];
      	j--;
      }
      vetor[j + 1] = chave;
	}
}
```
_tal que 'i' é o índice que vai do ínicio ao fim do vetor_  
_'j' é o índice que percorre os valores anteriores do vetor_  
_e 'chave' é o valor do vetor comparado no momento._

| índice = i | comparador = j | 1 | 2 | 3 | 4 |
|------------|----------------|---|---|---|---|
| Inicial    | -              | 7 | 5 | 1 | 2 |
| 1          | 0              | 5 | 7 | 1 | 2 |
| 2          | 1 → 0          | 1 | 5 | 7 | 2 |
| 3          | 2 → 1 → 0      | 1 | 2 | 5 | 7 |

> A aplicação do algoritmo em C pode ser visto no arquivo  
**InsertionSort.c** deste repositório
</details>

<details><summary> <h1>Merge Sort</h1> </summary>

## Pseudocódigo

```

//len retorna o tamanho do array

procedimento mergesort(vetor,inicio,fim)
  se(fim-inicio > 1)
    meio = floor((incio+fim)/2) //floor aproxima para um valor inteiro
    mergesort(vetor,inicio,meio)
    mergesort(vetor,meio,fim)
    merge(vetor,inicio,meio,fim)
  senão
    retorna vetor


procedimento merge(vetor,inicio,meio,fim)
  esquerda[] = vetor[inicio:meio] 
  direita[] = vetor[meio:fim]
  L,R = 0
  para contador = incio até fim
    se L >= len(esquerda)
      vetor[contador] = direita[R]
      R++
    senão se R >= len(direita)
      vetor[contador] = esquerda[L]
      L++
    senão se(esquerda[L] < direita[R])
      vetor[contador] = esquerda[L]
      L++
    senão
      vetor[contador] = direita[R]
      R++

```

</details>

<details><summary> <h1>Quick Sort</h1> </summary>

## Pseudocódigo

```
procedimento quickSort(vetor,primeiro,ultimo)
  se(primeiro < ultimo)
    chave = particionar(veto,primeiro,ultimo)
    quickSort(vetor,primeiro,chave-1)
    quickSort(vetor,chave+1,ultimo)

procedimento particionar(vetor,primeiro,ultimo)
  pivo = vetor[ultimo]
  indice = primeiro - 1
  para comparador = primeiro até ultimo
    se(vetor[comparador] <= pivo)
      indice++
      temp = vetor[indice]
      vetor[indice] = vetor[comparador]
      vetor[comparador] = temp
  retorna indice+1

```
</details>

<details>  <summary><h1> HeapSort </h1></summary>

## Pseudocódigo

```
procedimento heapify(vetor,indice,tamanho)
  esquerda = 2*indice+1
  direita = 2*indice+2
  maior = 0
  se (esquerda < tamanho && vetor[esquerda] > vetor[indice])
    maior = esquerda
  senão
    maior = indice
  se (direita < tamanho && vetor[direita] > vetor[maior])
    maior = direita
  se (maior != indice)
    temp = vetor[indice]
    vetor[indice] = vetor[maior]
    vetor[maior] = temp
    heapify(vetor,maior,tamanho)

procedimento construirHeap(vetor,tamanho)
 para indice = tamanho/2 - 1 até -1 passo -1
  heapify(vetor,indice,tamanho)

procedimento heapSort(vetor,tamanho)
  construirHeap(vetor,tamanho)
    para indice = tamano -1 até 0 passo - 1
      temp = vetor[0]
      vetor[0] = vetor[indice]
      vetor[indice] = temp
      heapify(vetor,0,indice)
```

 </details>


<details>  <summary><h1> Lista Linear Sequencial </h1></summary>

## Pseudocódigo

```
registro reg
  chave

registro Lista
  maximo
  ultimo
  reg dados[]

procedimento busca(lista,chave)
  indice = 0
  enquanto(indice < lista.ultimo)
    se(chave == lista.dados[indice].chave)
      retorna indice
    senão
      indice++
  retorna -1

procedimento insercao(lista,chave)
  se(lista.ultimo < lista.maximo)
    se(busca(lista,chave) == -1)
      lista.dados[lista.ultimo].chave = chave
      lista.ultimo++

procedimento excluir(lista,chave)
  posicao = busca(lista, chave)
  se(posicao == -1)
    retorna falso
  para indice = posicao até lista.ultimo-1
    lista.dados[indice] = lista.dados[indice+1]
  lista.ultimo--
  retorna verdadeiro  

```
</details>


<details>  <summary><h1> Lista Linear Sequencial Ordenada </h1></summary>

## Pseudocódigo

```
registro reg
  chave

registro Lista
  maximo
  ultimo
  reg dados[]

procedimento buscaBinaria(lista,chave)
  esquerda = 0
  direita = lista.ultimo-1
  enquanto(esquerda <= direita)
    meio = (esquerda+direita)/2
    se(lista.dados[meio] == chave)
      retorna meio
    senão se (lista.dados[meio].chave < chave)
      esquerda = meio+1
    senão
      direita = meio - 1
  retorna -1

procedimento insercaoOrdenada(lista,chave)
  se(lista.ultimo < lista.maximo)
    posicao = lista.ultimo
    enquanto (posicao > 0 && lista.dados[posicao-1].chave > chave)
      lista.dados[posicao] = lista.dados[posicao-1]
      posicao--
    lista.dados[posicao].chave = chave
    lista.ultimo++

procedimento excluir(lista,chave)
  posicao = buscaBinaria(lista, chave)
  se(posicao == -1)
    retorna falso
  para indice = posicao até lista.ultimo-1
    lista.dados[indice] = lista.dados[indice+1]
  lista.ultimo--
  retorna verdadeiro  

```

</details>

<details><summary><h1>Lista Encadeada</h1></summary>

## Pseudocódigo
```
registro No
  chave
  No prox

registro Lista
  No primeiro

procedimento buscar(chave,lista)
  aux = lista.primeiro
  anterior = NULO
  se (aux != NULO)
    enquanto(aux != && aux.chave != chave)
      anterior = aux
      aux = aux.prox
  retorna aux

procedimento inserir(chave, lista)
  se(buscar(chave,lista) == NULL)
    novo.chave = chave
    novo.prox = lista.primeiro
    lista.primeiro = novo
  
procedimento excluir(chave,lista)
  aux = buscar(chave,lista)
  anterior = NULO
  se(aux != NULO)
    se (anterior == NULO)
      lista.primeiro = aux.prox
    senão
      anterior.prox = aux.prox

```
</details>

<details><summary><h1>Tabela Hash</h1></summary>

## Pseudocódigo

```
registro cadeia
  chave
  cadeia prox

registro Lista
  cadeia inicio
  tamanho

procedimento inserir(lista,chave)
  novo.chave = valor;
  novo.proximo = lista.inicio
  lista.inicio - novo
  lista.tamanho++

procedimento buscar(lista,chave)
  aux = lista.inicio
  enquanto(aux && aux.chave != valor)
    aux = aux.proximo
  se (aux)
    retorna aux.chave
  retorna 0;

```

</details>