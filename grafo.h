//
// Created by person on 17/10/16.
//

#ifndef TP2_GRAFO_H
#define TP2_GRAFO_H

#include "vini.h"

typedef struct celula{

    char key[2];
    int number;

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

/*
 * Prototipo: void Le_entrada(Grafo_t* matriz_aux);
 *
 * Funcao: Le a matriz do mapa recebida pela entrada padrao e a passa para uma matriz auxiliar
 * que sera usada para montara matriz de adjacencia do grafo.
 *
 * Entrada: matriz que sera preenchida
 *
 * Saida: funcao void
 */

void Le_entrada(Grafo_t* matriz_aux);

/*
 * Prototipo: void Preenche_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, Vini_t* vini);
 *
 * Funcao: Preenche a matriz de adjacencia do grafo, baseado na matriz auxiliar com o mapa da fisica
 * passando, para cada celula, seu valor e seu caractere no mapa (caminho, parede, chave, porta ou buraco),
 * inserindo tambem na matriz de adjacencia o valor 1 se houver um caminho entre os dois vertices,
 * e 0 se nao houver.
 *
 * Entrada: Matriz auxiliar com o mapa, grafo a ser preenchido, e variavel vinicius que tera sua posicao inicial
 * definida
 *
 * Saida: funcao void
 */

void Preenche_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, Vini_t* vini);

/*
 * Prototipo: void Insere_vertice_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, int i, int j, int k, int k1);
 *
 * Funcao: Funcao auxiliar que insere um vertice e uma aresta na matriz de adjacencia do grafo assim
 * como os caracteres que representam o vertice no mapa.
 *
 * Entrada: matriz auxiliar do mapa, grafo com sua matriz de adjacencia, posicoes da matriz (i, j), posicoes
 * do grafo (k, k1).
 *
 * Saida: funcao void
 */

void Insere_vertice_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, int i, int j, int k, int k1);

/*
 * Prototipo: void Novos_vizinhos(Grafo_t* grafo,Grafo_t* matriz_aux, int vertex, int vizinho);
 *
 * Funcao: Define novos vizinhos para o vertice que antes era um buraco de minhoca e agora tornou-se
 * um caminho valido, podendo deslocar-se para suas posicoes adjacentes (se possivel)
 *
 * Entrada: Grafo com sua matriz de adjacencia, matriz com mapa, vertice do buraco de minhoca, vizinho
 * anterior do buraco de minhoca, com o qual nao ha mais conexao.
 *
 * Saida: funcao void
 */

void Novos_vizinhos(Grafo_t* grafo,Grafo_t* matriz_aux, int vertex, int vizinho);

void Apaga_matriz(Grafo_t* matriz);

void Apaga_grafo(Grafo_t* grafo);

void Apaga_vetor(int* vetor);

#endif //TP2_GRAFO_H
