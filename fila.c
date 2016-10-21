//
// Created by person on 20/10/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila_t* criaFila(){

    fila_t* fi = (fila_t*) malloc(sizeof(fila_t));

    fi->tam = 0;

    fi->cabeca = (celula_t*) malloc(sizeof(celula_t));
    fi->ultimo = fi->cabeca;

    fi->cabeca->coord_i = -1;
    fi->cabeca->coord_j = -1;
    fi->cabeca->prox = NULL;

    return fi;
}
void liberaFila(fila_t* fi){

    celula_t* aux_free;
    celula_t* aux_prox;

    aux_prox = fi->cabeca;

    while(aux_prox != NULL){
        aux_free = aux_prox;
        aux_prox = aux_prox->prox;
        free(aux_free);
    }
    free(fi);
}
void enfilera(fila_t* fi, int i, int j){

    celula_t* novo;
    novo = (celula_t*) malloc(sizeof(celula_t));

    novo->coord_i = i;
    novo->coord_j = j;

    fi->ultimo->prox = novo;
    fi->ultimo = novo;
    novo->prox = NULL;

    fi->tam++;
}
int* desenfilera(fila_t* fi){

    int *pos_aux;
    celula_t* aux;
    aux = fi->cabeca->prox;
    fi->cabeca->prox = aux->prox;
    pos_aux = (int*)calloc(2, sizeof(int));

    pos_aux[0] = aux->coord_i;
    pos_aux[1] = aux->coord_j;

    free(aux);

    if(fi->tam == 1) fi->ultimo = fi->cabeca;

    fi->tam--;

    return pos_aux;
}
int FilaVazia(fila_t* fi){

    if(fi->tam == 0) return 1;
    else return 0;
}
