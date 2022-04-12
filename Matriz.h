/*especificação do TAD Lista de Matrizes 
com funções de criação, inserção, retirada, impressão e liberação de memória; 
o retira só vai fazer sentido considerando a posição da matriz na lista.*/

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matriz Matriz;

struct matriz
{
    int** mat;
    int nlinhas;
    int ncolunas;
    char* nome;
};

char *strdup(const char *c);

Matriz* inicializaMatriz (int nlinhas, int ncolunas, char* nome);

void modificaElemento (Matriz* mat, int linha, int coluna, int elem);

char* recuperaNome(Matriz* mat);

int recuperaElemento(Matriz* mat, int linha, int coluna);

int recuperaNColunas (Matriz* mat);

int recuperaNLinhas (Matriz* mat);

Matriz* transposta (Matriz* mat);

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2);

void imprimeMatriz(Matriz* mat);

void destroiMatriz(Matriz* mat);


#endif /*LISTAMAT_H_*/