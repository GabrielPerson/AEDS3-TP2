//
// Created by person on 17/10/16.
//

#include "grafo.h"

Grafo_t* Cria_grafo(int linha, int coluna){

    Grafo_t* grafo;
    int i = 0;

    grafo = (Grafo_t*) calloc(1, sizeof(Grafo_t));

    grafo->mapa = (Celula_t**)calloc(linha, sizeof(Celula_t*));
    for(i = 0; i < linha; i++)
        grafo->mapa[i] = (Celula_t*)calloc(coluna, sizeof(Celula_t));

    return grafo;

}

