//
// Created by person on 11/10/16.
//

/*TRABALHO PRATICO 2 AEDSIII - CAMINHANDO NA FISICA (GRAFOS)
 *
 *  ENTRADAS: N, M, T -> TAMANHO DA MATRIZ (NxM) E NUMERO DE CHAVES AO MESMO TEMPO
 *  REPRESENTACAO MAPA (ENTRADA) -> '.' - POSICOES LIVRE
 *                                  '#' - OBSTACULOS
 *                                  'c','d,'h,'s' - CHAVES
 *                                  'C','D,'H,'S' - PORTAS
 *                                  'V' - POSICAO INICIAL DE VINICIUS
 *                                  'E' - SAIDA DA FISICA
 *                                  'X,Y' - 0<X,Y<9 (POSICAO FINAL DO BURADO DE MINHOCA)
 *
 *  SAIDA - TEMPO MINIMO PARA SAIR DA FISICA (SE IMPOSSIVEL -> IMPRIMIR -1)
 *
 */

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

    /*int i = 0, j = 0;

    for(i = 0; i < grafo->num_vertex;i++){
        for(j = 0; j < grafo->num_vertex; j++)
            printf("%c ", grafo->mapa[i][j].key[0]);
        printf("\n");
    }
    for(i = 0; i < grafo->num_vertex;i++){
        for(j = 0; j < grafo->num_vertex; j++)
            printf("%d ", grafo->mapa[i][j].number);
        printf("\n");
    }*/

    //int i = 0, j = 0;

    saida = Busca_saida(grafo, matriz_aux ,vini, dist, ant);

    Apaga_matriz(matriz_aux);

    if(saida == -1)
        printf("-1\n");
    else
        printf("%d\n", dist[saida]);
    /*
    int i = 0;
    for(i = 0; i < grafo->num_vertex;i++)
        printf("%d ", ant[i]);*/

    Apaga_vini(vini);
    Apaga_vetor(dist);
    Apaga_vetor(ant);
    Apaga_grafo(grafo);


    return 0;
}