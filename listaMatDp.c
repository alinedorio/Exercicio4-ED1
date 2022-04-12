#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaMatDp.h"
#include "Matriz.h"

struct listadp{
  Matriz* mat;
  ListaDp* prox;
  ListaDp* ant;
};

ListaDp* inicLista(void){
  return NULL;
}

void InsereLista (ListaDp* lista, Matriz* mat){
  ListaDp* nova = malloc (sizeof(ListaDp));

  nova->mat = mat;
  nova->prox = lista;
  nova->ant = NULL;

  if (lista != NULL){
    lista->ant = nova;
  }
}

void ImprimeLista (ListaDp* lista){
  ListaDp* aux;

  for (aux = lista; aux != NULL; aux = aux -> prox){
    imprimeMatriz(aux->mat);
    printf("\n");
  }
}

static ListaDp* busca (ListaDp* lista, Matriz* chave){
  ListaDp* aux;
  char* nome;
  chave->nome = strdup(nome);

  for(aux = lista; aux != NULL; aux = aux->prox){
    if(strcmp(recuperaNome(aux->mat), nome)){
      return aux;
    }
  }

  return NULL;
}

ListaDp* RetiraLista (ListaDp* lista, Matriz* chave){
  ListaDp* aux = busca(lista, chave);

//nao encontrou ou lista vazia
  if (aux == NULL){
    return NULL;
  }

//se nao for primeira celula
  if (aux->ant != NULL){
    aux->ant->prox = aux->prox;
  }
  else{
    lista = aux->prox;
    lista->ant = NULL;
  }

  //se nao for ultima celula
  if (aux->prox != NULL){
    aux->prox->ant = aux->ant;
  }
  else{
    aux->ant->prox = NULL;
  }
  
  free(chave);
  free(aux);
  return lista;
}

void DestroiLista (ListaDp* lista){
  ListaDp* p = lista;
  ListaDp* t;
while(p != NULL){
  t = p->prox;
  destroiMatriz(p->mat);
  free(p);
  p = t;
}

free(lista);

}
