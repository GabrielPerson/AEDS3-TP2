//
// Created by person on 17/10/16.
//

#include "grafo.h"
#include <stdlib.h>

Grafo_t* Cria_grafo(int linha, int coluna){

    Grafo_t* grafo;
    int i = 0;

    grafo = (Grafo_t*) calloc(1, sizeof(Grafo_t));

    grafo->coluna = coluna;
    grafo->linha = linha;

    grafo->mapa = (Celula_t**)calloc(grafo->linha, sizeof(Celula_t*));
    for(i = 0; i < linha; i++)
        grafo->mapa[i] = (Celula_t*)calloc(grafo->coluna, sizeof(Celula_t));

    return grafo;

}

void Apaga_grafo(Grafo_t* grafo){

    int i =0;

    for(i = 0; i < grafo->linha;i++)
        free(grafo->mapa[i]);
    free(grafo->mapa);

    free(grafo);

}