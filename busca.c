//
// Created by person on 20/10/16.
//

#include "busca.h"
#include <stdlib.h>


int Menor_caminho(Grafo_t* grafo, int coord_i, int coord_j, int* dist, int* ant){

    int i = 0, cont = grafo->num_vertex, *visita, v;

    visita = (int*)calloc(grafo->num_vertex, sizeof(int));

    dist[grafo->mapa[coord_i][coord_j].number] = 0;
    while(cont > 0){

        v = Menor_distancia(dist, visita, grafo->num_vertex);
        if(v == -1) break;
        visita[v] = 1;
        cont--;

    }

}


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
}