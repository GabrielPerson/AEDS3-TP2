//
// Created by person on 17/10/16.
//

#ifndef TP2_GRAFO_H
#define TP2_GRAFO_H


#include "vini.h"

typedef struct celula{

    char key[2];
    int number;
    int cor; //0 -> branco 1-> cinza 2-> preto

}Celula_t;

typedef struct grafo{

    Celula_t** mapa;
    int coluna;
    int linha;
    int num_vertex;

}Grafo_t;


Grafo_t* Cria_matriz_aux(int linha, int coluna);

Grafo_t* Cria_grafo(int num_vertices);

int* Cria_vetor(int num_vertex);

void Le_entrada(Grafo_t* matriz_aux);

void Preenche_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, Vini_t* vini);

void Insere_vertice_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, int i, int j, int k);

void Apaga_matriz(Grafo_t* matriz);

void Apaga_grafo(Grafo_t* grafo);


#endif //TP2_GRAFO_H
