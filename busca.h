//
// Created by person on 20/10/16.
//

#include "grafo.h"

#ifndef TP2_BUSCA_H
#define TP2_BUSCA_H

int Menor_caminho_saida(Grafo_t* grafo, int coord_i, int coord_j, int* dist, int* ant);

int Menor_distancia(int* dist, int* visita, int num_vertex);

#endif //TP2_BUSCA_H
