/*Implementação do TAD Lista de Matrizes. 
Nesta implementação, não serão criadas e nem liberadas matrizes. 
Isso será função do cliente testador. 
Apenas manipulem células da lista, como explicado nos vídeos.*/

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include "Matriz.h"
/*struct matriz
{
    int** mat;
    int nlinhas;
    int ncolunas;
    char* nome;
};*/

Matriz* inicializaMatriz (int nlinhas, int ncolunas, char* nome){
    int i;
    Matriz* mat = malloc(sizeof(Matriz));

    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;
    mat->nome = strdup(nome);

    mat->mat = (int**) malloc(nlinhas * sizeof(int*));
    
    for (i = 0; i < nlinhas; i++){
        mat->mat[i] = (int*) malloc(ncolunas * sizeof(int));
    }

    return mat;

}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}

char* recuperaNome(Matriz* mat){
  return mat->nome;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
return mat->mat[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat){
    int i, j;
    
    Matriz* transposta = inicializaMatriz(mat->ncolunas, mat->nlinhas, mat->nome);
    
    for(i=0; i < mat->nlinhas; i++){
        for(j=0; j < mat->ncolunas; j++){
            transposta->mat[j][i] = mat->mat[i][j];
        }
    }

    return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int i, j, k, aux = 0;
    
    if(mat1 == NULL || mat2 == NULL){
        return NULL;
    }

    if(mat1->ncolunas != mat2->nlinhas){
        return NULL;
    }

    Matriz* mult = malloc(sizeof(Matriz));

    mult->mat = malloc(sizeof(int*) * mat1->nlinhas);

    for(i = 0; i < mat1->nlinhas; i++){
        mult->mat[i] = malloc(sizeof(int) * mat2->ncolunas);
    }

    mult->nlinhas = mat1->nlinhas;
    mult->ncolunas = mat2->ncolunas;

    for(i = 0; i < mult->nlinhas; i++){
        for(j = 0; j < mult->ncolunas; j++){
            for(k = 0; k < mat1->ncolunas; k++){
                aux += mat1->mat[i][k] * mat2->mat[k][j];
            }

            mult->mat[i][j] = aux;
            aux = 0;
        }
    }

    return mult;

}

void imprimeMatriz(Matriz* mat){
    int i, j;

     if(mat == NULL){
        return;
    }

     for(i=0; i<mat->nlinhas; i++){
        for(j=0; j<mat->ncolunas; j++){
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    int i,j;

     if(mat == NULL){
        return;
    }

    for(i = 0; i < mat->nlinhas; i++){
        free(mat->mat[i]);
        }
    free(mat);
}