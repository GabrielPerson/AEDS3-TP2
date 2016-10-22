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
 *  SAIDA - TEMPO MINIMO PARA SAIR DA FISICA (SE IMPOSSIVEL - IMPRIMIR -1)
 *
 */

/* PROGRESSO DO TP
 *
 * 1 - PASSAR INPUT PARA MATRIZ GRAFO - OK
 * 2 - CRIAR VINICIUS - OK
 * 3 - VER ALGORITMO DE BUSCA EM LARGURA
 * 4 - IMPLEMENTAR ALGORITMO
 * 5 - TENTAR IMPLEMENTAR O DJIKSTRA
 * 6 - TA TUDO OK ??
 * 7 - SERA MSM ???
 * 8 - SE TIVER OK VAI PRA DOC
 *
 */

#include <stdio.h>
#include "grafo.h"
#include <stdlib.h>


int main(){

    int lin_matriz = 0, col_matriz = 0, max_chave = 0;
    char lixo;
    //int* ant, *dist;

    Grafo_t* matriz_aux;
    Grafo_t* grafo;
    Vini_t* vini;

    scanf("%d %d %d", &lin_matriz, &col_matriz, &max_chave);

    matriz_aux = Cria_matriz_aux(lin_matriz, col_matriz);
    grafo = Cria_grafo(matriz_aux->num_vertex);
    vini = Cria_vini();

    scanf("%c", &lixo);

    Le_entrada(matriz_aux);
    Preenche_grafo(matriz_aux, grafo, vini);
    //ant = Cria_vetor(lin_matriz*col_matriz);
    //dist = Cria_vetor(lin_matriz*col_matriz);

    printf("%d\n", vini->pos);


    Apaga_vini(vini);

    Apaga_grafo(grafo);
    Apaga_matriz(matriz_aux);

    return 0;
}