//Este arquivo contém a main que deve testar o seu TAD Lista de Matrizes.


#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include "listaMatDp.h"
#include "Matriz.h"

int main(void) {
  //a. Gerar algumas matrizes para teste (umas 3 ou 4 matrizes já seria suficiente);

  Matriz* a = inicializaMatriz(3, 3, "a");
  Matriz* b = inicializaMatriz(2, 3, "b");
  Matriz* c = inicializaMatriz(3, 2, "c");


  //b. Inicializar uma lista encadeada;
  ListaDp* listinha = inicLista();

  //c. Inserir as matrizes na lista;
  InsereLista(listinha, a);
  InsereLista(listinha, b);
  InsereLista(listinha, c);

  //d. Inicializar outra lista encadeada;
  ListaDp* listao = inicLista();

  //e. Inserir as matrizes transpostas na segunda lista encadeada;
  Matriz* d = transposta(a);
  Matriz* e = transposta(b);
  Matriz* f = transposta(c);

  InsereLista(listao, d);
  InsereLista(listao, e);
  InsereLista(listao, f);

  //f. Imprima as listas e veja se estão corretas!!!
  printf("pre retirada\n");
  ImprimeLista(listinha);
  printf("\n");
  ImprimeLista(listao);

  //g. Retire algumas matrizes para verificar se o retira está funcionando (retire da primeira posição, última posição e caso comum);

  ListaDp* num1 = RetiraLista(listinha, a);
  ListaDp* num2 = RetiraLista(listao, d);
  ListaDp* num3 = RetiraLista(listinha, b);

  printf("pos retirada\n");
  ImprimeLista(listinha);
  printf("\n");
  ImprimeLista(listao);
  
  //h. Insira as matrizes novamente para verificar se o retira não “quebrou” a lista;
  InsereLista(listinha, a);
  InsereLista(listinha, b);
  InsereLista(listao, d);

  printf("pos nova insercao\n");
  ImprimeLista(listinha);
  printf("\n");
  ImprimeLista(listao);

  //i. Libere as listas!
  DestroiLista(listinha);
  DestroiLista(listao);

  return 0;
}