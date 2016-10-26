//
// Created by person on 20/10/16.
//


#ifndef TP2_BUSCA_H
#define TP2_BUSCA_H

#include "grafo.h"


int Busca_saida(Grafo_t* grafo, Vini_t* vini, int* dist, int* ant);

int Menor_distancia(int* dist, int* visita, int num_vertex);

int Abre_porta(Grafo_t* grafo, Vini_t* vini, int vertex, int vizinho);

int Eh_porta(Grafo_t* grafo, int vertex, int vizinho);

int Eh_chave(Grafo_t* grafo, int vertex);

void Pega_chave(Grafo_t* grafo, Vini_t* vini, int v);

int Check_saida(Grafo_t* grafo, int* dist, int vertice, int vizinho);

void Check_vizinhos(Grafo_t* grafo, Vini_t* vini, int* dist, int *ant, int vertex, int i, int* chegou_saida, int* saida, int whole);

#endif //TP2_BUSCA_H
