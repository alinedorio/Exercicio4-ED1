#ifndef LISTAMATDP_H_
#define LISTAMATDP_H_

#include <stdio.h>
#include "Matriz.h"

typedef struct listadp ListaDp;

ListaDp* inicLista();

void InsereLista (ListaDp* lista, Matriz* mat);

void ImprimeLista (ListaDp* lista);

ListaDp* RetiraLista (ListaDp* lista, Matriz* chave);

void DestroiLista (ListaDp* lista);

#endif