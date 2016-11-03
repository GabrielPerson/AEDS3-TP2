//
// Created by person on 20/10/16.
//


#ifndef TP2_BUSCA_H
#define TP2_BUSCA_H

#include "grafo.h"

/*
 * Prototipo: int Busca_saida(Grafo_t* grafo, Grafo_t* matriz_aux ,Vini_t* vini, int* dist, int* ant);
 *
 * Funcao: Funcao principal que ira procurar o menor caminho entre a posicao inicial de vinicius e a
 * saida da fisica. Usa dois lacos iterativos. No primeiro (infinito) verifica qual vertice mais proximo da saida
 * ainda nao foi visitado. Encerra quando não houverem mais vertices possiveis a serem visitados.
 * No segundo, percorre cada vizinho do vertice verificando se seria uma porta, ou vizinho de um buraco de minhoca,
 * tambem atualizando sua distancia, caso necessario.
 *
 * Entrada: Grafo com sua matriz de adjacencia, matriz auxlilar com o mapa, variavel vinicius, vetor de distancias
 * dos vertices e vetor com o vertice anterior de cada vertice.
 *
 * Saida: retorna vertice de saida.
 */

int Busca_saida(Grafo_t* grafo, Grafo_t* matriz_aux ,Vini_t* vini, int* dist, int* ant);

/*
 * Prototipo:  int Menor_distancia(int* dist, int* visita, int num_vertex);
 *
 * Funcao: PErcorre vetor de visita e distancia dos vertices, procurando pelo primeiro
 * vertice nao visitado que tenha distancia maior ou igual a 0.
 *
 * Entrada: Vetores de distancia e visita dos vertices, vertice inicial
 *
 * Saida: vetice mais proximo da entrada e nao visitado.
 */

int Menor_distancia(int* dist, int* visita, int num_vertex);


//verifica se pode-se abrir a porta do vertice vizinho.
int Abre_porta(Grafo_t* grafo, Vini_t* vini, int vertex, int vizinho);

//verifica se o vertice atual é uma porta.
int Eh_porta(Grafo_t* grafo, int vertex, int vizinho);


//verifica se o vetice atual é uma chave.
int Eh_chave(Grafo_t* grafo, int vertex);


//verifica se pode-se pegar a chave do vertice atual
void Pega_chave(Grafo_t* grafo, Vini_t* vini, int v);


//verifica se ja se chegou na saida.
int Check_saida(Grafo_t* grafo, int* dist, int vizinho);


//verifica, para cada vertice qual vizinho é valido para continuar o caminho.
void Check_vizinhos(Grafo_t* grafo, Vini_t* vini, int* dist, int *ant, int* visita, int vertex, int i, int* chegou_saida, int* saida, int whole,int whole_fechado);


//verifica, se o vizinho de um buraco de minhoca ja foi visitado e estao no caminho ja percorrido.
int No_caminho(int* ant, int vertex, int vizinho, int inicio);

#endif //TP2_BUSCA_H
