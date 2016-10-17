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

#include <stdio.h>
#include "grafo.h"



int main(){

    int lin_matriz = 0, col_matriz = 0, max_chave = 0;
    int i = 0, j = 0;
    char aux[2];

    Grafo_t* grafo;

    scanf("%d %d %d", &lin_matriz, &col_matriz, &max_chave);

    grafo = Cria_grafo(lin_matriz, col_matriz);

    for(i = lin_matriz-1; i >= 0; i++) {
        for(j = 0; j < col_matriz; j++){
           scanf("%c", &aux[0]);
            if(aux[0] > 47 && aux[0] < 56) {
                scanf("%c", &aux[1]);
                grafo->mapa[i][j].whole[0] = aux[0];
                grafo->mapa[i][j].whole[1] = aux[1];
            }
            else
                grafo->mapa[i][j].key = aux[0];

            grafo->mapa[i][j].cor = 0;
        }
    }


    return 0;
}