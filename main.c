//
// Created by person on 11/10/16.
//


#include <stdio.h>
#include "grafo.h"
#include "busca.h"


int main(){

    int lin_matriz = 0, col_matriz = 0, max_chave = 0;
    char lixo;
    int* ant, *dist;
    int saida = -1;

    Grafo_t* matriz_aux;
    Grafo_t* grafo;
    Vini_t* vini;

    scanf("%d %d %d", &lin_matriz, &col_matriz, &max_chave);

    matriz_aux = Cria_matriz_aux(lin_matriz, col_matriz);
    grafo = Cria_grafo(matriz_aux->num_vertex);
    ant = Cria_vetor(lin_matriz*col_matriz);
    dist = Cria_vetor(lin_matriz*col_matriz);
    vini = Cria_vini(max_chave);

    scanf("%c", &lixo);

    Le_entrada(matriz_aux);
    Preenche_grafo(matriz_aux, grafo, vini);

    saida = Busca_saida(grafo, matriz_aux ,vini, dist, ant);

    Apaga_matriz(matriz_aux);

    if(saida == -1)
        printf("-1\n");
    else
        printf("%d\n", dist[saida]);

    Apaga_vini(vini);
    Apaga_vetor(dist);
    Apaga_vetor(ant);
    Apaga_grafo(grafo);


    return 0;
}