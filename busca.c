//
// Created by person on 20/10/16.
//

#include "busca.h"
#include <stdlib.h>
//#include "fila.h"

/* IMPLEENTACAO DE BUSCA DO MENOR CAMINHO DA SAIDA
 *  1 - USA-SE UMA FILA PARA BUSCA EM LARGURA - VERIFICA-SE TODOS OS VIZINHOS DE D = 1 DO VERTICE E ADICIONA-OS NA FILA E ASSIM VAI.
 *          - ADICIONA-SE OS VERTICES BRANCOS VIZINHOS NA FILA (I,J+1 / I+1,J / I,J-1 / I-1,J) (funcao pra verificar se enfilera)
 *  2 - ESTANDO NO VERTICE -> DEFINE SUA DISTANCIA
 *  3 - VERIFICA SE EH UMA CHAVE OU UM BURACO
 *      -> CHAVE - VERIFICA SE JA SE ATINGIU O MAXIMO DE CHAVES
 *               - VERIFICA SE JA POSSUI CHAVE (PODE PEGAR OU NAO)
 *      -> BURACO - POSICAO VIRA `.`
 *                - ADICIONA POSICAO NA FILA
 *  4 - VERIFICA-SE O PROXIMO VERTICE
 *      - SE '#' NAO AVANCA (VERIFICA OUTROS VIZINHOS)
 *      - SE PORTA VERIFICA-SE SE TEM CHAVE(SE TIVER, ADD NA FILA)
 *  5 - USA-SE UMA VARIAVEL PARA VERIFICA SE JA CHEGOU-SE ALGUMA VEZ NA SAIDA
 *      - SE SIM, E DISTANCIA DO VERTICE ATUAL FOR MAIOR, PARA.
 *
 */



/*
int Menor_caminho(Grafo_t* grafo, int coord_i, int coord_j, int* dist, int* ant){

    int i = 0, cont = grafo->num_vertex, *visita, v, find_exit = 0;
    int *pos_vertex;
    fila_t* fila;

    visita = (int*)calloc(grafo->num_vertex, sizeof(int));
    pos_vertex = (int*)calloc(2, sizeof(int));
    fila = criaFila();

    dist[grafo->mapa[coord_i][coord_j].number] = 0;
    enfilera(fila, coord_i, coord_j);
    while(!FilaVazia(fila)){

        pos_vertex = desenfilera(fila);


    }

}
*/
/*
int Menor_distancia(int* dist, int* visita, int num_vertex){

    int i = 0, menor = -1, primeiro = 1;

    for(i = 0; i < num_vertex;i++){
        if(dist[i] >= 0 && visita[i] == 0){
            if(primeiro == 1){
                menor = i;
                primeiro = 0;
            }
            else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
        return menor;
}*/