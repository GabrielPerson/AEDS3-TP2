//
// Created by person on 17/10/16.
//

#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
#include "vini.h"

Grafo_t* Cria_grafo(int linha, int coluna){

    Grafo_t* grafo;
    int i = 0;

    grafo = (Grafo_t*) calloc(1, sizeof(Grafo_t));

    grafo->coluna = coluna;
    grafo->linha = linha;
    grafo->num_vertex = linha*coluna;

    grafo->mapa = (Celula_t**)calloc(grafo->linha, sizeof(Celula_t*));
    for(i = 0; i < linha; i++)
        grafo->mapa[i] = (Celula_t*)calloc(grafo->coluna, sizeof(Celula_t));

    return grafo;

}

int* Cria_vetor(int num_vertex){

    int i = 0;
    int* vetor;

    vetor = (int*)calloc(num_vertex, sizeof(int));
    for(i = 0; i < num_vertex;i++)
        vetor[i] = -1;

    return vetor;
}

Vini_t* Preenche_grafo(Grafo_t* grafo){

    int i = 0, j = 0, k = 0;
    char aux[2];
    Vini_t* vini;

    for(i = grafo->linha-1; i >= 0; i--) {
        for(j = 0; j < grafo->coluna; j++){
            scanf("%c ", &aux[0]);
            if(aux[0] == 'V')
                vini = Cria_vini(j, i);

            if(aux[0] > 47 && aux[0] < 56) {
                scanf("%c ", &aux[1]);
                grafo->mapa[i][j].key[0] = aux[0];
                grafo->mapa[i][j].key[1] = aux[1];
            }
            else
                grafo->mapa[i][j].key[0] = aux[0];

            grafo->mapa[i][j].cor = 0;
            grafo->mapa[i][j].number = k;
            k++;
        }
    }
    return vini;

}

void Apaga_grafo(Grafo_t* grafo){

    int i =0;

    for(i = 0; i < grafo->linha;i++)
        free(grafo->mapa[i]);
    free(grafo->mapa);

    free(grafo);

}


