//
// Created by person on 17/10/16.
//

#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

Grafo_t* Cria_matriz_aux(int linha, int coluna){

    Grafo_t* grafo;
    int i = 0;

    grafo = (Grafo_t*) calloc(1, sizeof(Grafo_t));

    grafo->coluna = coluna;
    grafo->linha = linha;
    grafo->num_vertex = linha*coluna;

    grafo->mapa = (Celula_t**)calloc(grafo->linha, sizeof(Celula_t*));
    for(i = 0; i < linha; i++)
        grafo->mapa[i] = (Celula_t*)calloc(grafo->coluna, sizeof(Celula_t));

    return grafo;

}

Grafo_t* Cria_grafo(int num_vertex){

    Grafo_t* grafo;
    int i = 0;

    grafo = (Grafo_t*) calloc(1, sizeof(Grafo_t));

    grafo->num_vertex = num_vertex;
    grafo->linha = 0;
    grafo->coluna = 0;

    grafo->mapa = (Celula_t**)calloc(grafo->num_vertex, sizeof(Celula_t*));
    for(i = 0; i < grafo->num_vertex; i++)
        grafo->mapa[i] = (Celula_t*)calloc(grafo->num_vertex, sizeof(Celula_t));

    return grafo;

}

int* Cria_vetor(int num_vertex){

    int i = 0;
    int* vetor;

    vetor = (int*)calloc(num_vertex, sizeof(int));
    for(i = 0; i < num_vertex;i++)
        vetor[i] = -1;

    return vetor;
}

void Le_entrada(Grafo_t* matriz_aux){

    int i = 0, j = 0;
    char aux[2];

    for(i = matriz_aux->linha-1; i >= 0; i--) {
        for(j = 0; j < matriz_aux->coluna; j++){
            scanf("%c ", &aux[0]);

            if(aux[0] > 47 && aux[0] < 58) {
                scanf("%c ", &aux[1]);
                matriz_aux->mapa[i][j].key[0] = aux[0];
                matriz_aux->mapa[i][j].key[1] = aux[1];
            }
            else
                matriz_aux->mapa[i][j].key[0] = aux[0];
        }
    }
}

void Preenche_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, Vini_t* vini){

    int i = 0, j = 0, k = 0;
    int lim_dir = 0, lim_esq = 0;
    int whole_i = 0, whole_j = 0, vertex_whole = 0;

    for(i = 0; i < matriz_aux->linha;i++){
        lim_dir = (i + 1) * matriz_aux->coluna;
        lim_esq = (i * matriz_aux->coluna);
        for(j = 0; j < matriz_aux->coluna;j++){
            grafo->mapa[k][k].key[0] = matriz_aux->mapa[i][j].key[0];
            grafo->mapa[k][k].key[1] = matriz_aux->mapa[i][j].key[1];
            if(matriz_aux->mapa[i][j].key[0] != '#') {
                if(matriz_aux->mapa[i][j].key[0] == 'V')
                    vini->pos = k;
                if(matriz_aux->mapa[i][j].key[0] > 47 && matriz_aux->mapa[i][j].key[0] < 58){
                    whole_i = (int) matriz_aux->mapa[i][j].key[0] - 48;
                    whole_j = (int) matriz_aux->mapa[i][j].key[1] - 48;
                    vertex_whole = matriz_aux->coluna * whole_i  + whole_j;
                    grafo->mapa[k][vertex_whole].number = 1;
                    grafo->mapa[k][vertex_whole].key[0] = matriz_aux->mapa[whole_i][whole_j].key[0];
                    grafo->mapa[k][vertex_whole].key[1] = matriz_aux->mapa[whole_i][whole_j].key[1];
                }
                else {
                    if (k + 1 < lim_dir)
                        Insere_vertice_grafo(matriz_aux, grafo, i, j + 1, k, k + 1);

                    if (k - 1 >= lim_esq)
                        Insere_vertice_grafo(matriz_aux, grafo, i, j - 1, k, k - 1);

                    if (k + matriz_aux->coluna < grafo->num_vertex)
                        Insere_vertice_grafo(matriz_aux, grafo, i + 1, j, k, k + matriz_aux->coluna);

                    if (k - matriz_aux->coluna >= 0)
                        Insere_vertice_grafo(matriz_aux, grafo, i - 1, j, k, k - matriz_aux->coluna);
                }
            }
            k++;
        }
    }
}

void Insere_vertice_grafo(Grafo_t* matriz_aux, Grafo_t* grafo, int i, int j, int k, int k1){

    if(matriz_aux->mapa[i][j].key[0] != '#'){
        grafo->mapa[k][k1].number = 1;
        if(matriz_aux->mapa[i][j].key[0] > 47 && matriz_aux->mapa[i][j].key[0] < 58){
            grafo->mapa[k][k1].key[0] = matriz_aux->mapa[i][j].key[0];
            grafo->mapa[k][k1].key[1] = matriz_aux->mapa[i][j].key[1];
        } else
            grafo->mapa[k][k1].key[0] = matriz_aux->mapa[i][j].key[0];
    } else
        grafo->mapa[k][k1].number = 0;
}

void Novos_vizinhos(Grafo_t* grafo, Grafo_t* matriz_aux, int vertex, int vizinho) {

    grafo->mapa[vertex][vizinho].number = 0;

    if (vertex - 1 >= 0) {
        if (grafo->mapa[vertex - 1][vertex - 1].key[0] != '#')
            grafo->mapa[vertex][vertex - 1].number = 1;
    }
    if (vertex + 1 < grafo->num_vertex) {
        if (grafo->mapa[vertex + 1][vertex + 1].key[0] != '#')
            grafo->mapa[vertex][vertex + 1].number = 1;
    }
    if (vertex - matriz_aux->coluna >= 0){
        if (grafo->mapa[vertex - matriz_aux->coluna][vertex - matriz_aux->coluna].key[0] != '#')
            grafo->mapa[vertex][vertex - matriz_aux->coluna].number = 1;
    }
    if(vertex+matriz_aux->coluna < grafo->num_vertex) {
        if (grafo->mapa[vertex + matriz_aux->coluna][vertex + matriz_aux->coluna].key[0] != '#')
            grafo->mapa[vertex][vertex + matriz_aux->coluna].number = 1;
    }
}


void Apaga_matriz(Grafo_t* matriz){

    int i =0;

    for(i = 0; i < matriz->linha;i++)
        free(matriz->mapa[i]);
    free(matriz->mapa);

    free(matriz);

}

void Apaga_grafo(Grafo_t* grafo){

    int i =0;

    for(i = 0; i < grafo->num_vertex;i++)
        free(grafo->mapa[i]);
    free(grafo->mapa);

    free(grafo);

}

void Apaga_vetor(int* vetor){

    free(vetor);
    vetor = NULL;

}
