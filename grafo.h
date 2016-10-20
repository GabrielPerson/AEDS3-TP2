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


Grafo_t* Cria_grafo(int linha, int coluna);

int* Cria_vetor(int num_vertex);

Vini_t* Preenche_grafo(Grafo_t* grafo);

void Apaga_grafo(Grafo_t* grafo);


#endif //TP2_GRAFO_H
