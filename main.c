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



int main(){

    int lin_matriz = 0, col_matriz = 0, max_chave = 0;
    int i = 0, j = 0, vini_x = 0, vini_y = 0;
    char aux[2], lixo;

    Grafo_t* grafo;

    scanf("%d %d %d", &lin_matriz, &col_matriz, &max_chave);

    grafo = Cria_grafo(lin_matriz, col_matriz);

    scanf("%c", &lixo);

    for(i = grafo->linha-1; i >= 0; i--) {
        for(j = 0; j < grafo->coluna; j++){
           scanf("%c ", &aux[0]);
            if(aux[0] == 'V'){
                vini_x = j;
                vini_y = i;
            }
            if(aux[0] > 47 && aux[0] < 56) {
                scanf("%c ", &aux[1]);
                grafo->mapa[i][j].key[0] = aux[0];
                grafo->mapa[i][j].key[1] = aux[1];
            }
            else
                grafo->mapa[i][j].key[0] = aux[0];

            grafo->mapa[i][j].cor = 0;
        }
    }

    for(i = 0; i < grafo->linha;i++){
        for(j = 0; j < grafo->coluna;j++){
            if(grafo->mapa[i][j].key[0] > 47 && grafo->mapa[i][j].key[0] < 56)
                printf("%c%c ", grafo->mapa[i][j].key[0], grafo->mapa[i][j].key[1]);
            else
                printf("%c ", grafo->mapa[i][j].key[0]);
        }
        printf("\n");
    }

    Apaga_grafo(grafo);

    return 0;
}