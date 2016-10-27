//
// Created by person on 20/10/16.
//

#include "busca.h"
#include <stdlib.h>

int Busca_saida(Grafo_t* grafo, Grafo_t* matriz_aux, Vini_t* vini, int* dist, int* ant){

    int i = 0, k = 0, cont = grafo->num_vertex, *visita, v;
    int  whole = 0, chegou_saida = 0, saida = -1, vizinho = -1;
    int passou_chave = 0, whole_fechado = -1;

    visita = (int*)calloc(grafo->num_vertex, sizeof(int));
    dist[vini->pos] = 0;

    while(cont > 0){

        v = Menor_distancia(dist, visita, grafo->num_vertex);
        if(v == -1)
            break;

        visita[v] = 1;
        cont--;

        whole = 0;
        //TODO o hole qnd fecha, ele pode ser acessado de novo ? e os que vem antes dele? podem ?
        if(grafo->mapa[v][v].key[0] > 47 && grafo->mapa[v][v].key[0] < 59){
            whole_fechado = v;
            whole = 1;
            grafo->mapa[v][v].key[0] = '.';
        }

        if(chegou_saida && dist[v] > dist[saida])
            break;

        if(Eh_chave(grafo,v) && vini->cont_chave == vini->max_chave){
            k = ant[v];
            passou_chave = 0;
            while(k != vini->pos){
                if(Eh_chave(grafo,k)){
                    passou_chave = 1;
                    break;
                }
                else
                    k = ant[k];
            }
            if(!passou_chave){
                vini->cont_chave--;
                Pega_chave(grafo,vini,v);
            }
        }

        if(vini->cont_chave < vini->max_chave && Eh_chave(grafo,v))
            Pega_chave(grafo, vini, v);

        for(i = 0; i < grafo->num_vertex;i++) {
            if (grafo->mapa[v][i].number == 1){
                vizinho = i;
                Check_vizinhos(grafo, vini, dist, ant, visita, v, i, &chegou_saida, &saida, whole, whole_fechado);
            }
        }
        if(whole)
            Novos_vizinhos(grafo,matriz_aux,v, vizinho);

    }
    Apaga_vetor(visita);

    return saida;
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

int Eh_chave(Grafo_t* grafo, int vertex){

    switch (grafo->mapa[vertex][vertex].key[0]){
            case 'c':
                return 1;
            case 'd':
                return 1;
            case 'h':
                return 1;
            case 's':
                return 1;
            default:
                return 0;
        }

}

void Pega_chave(Grafo_t* grafo, Vini_t* vini, int v){

        switch (grafo->mapa[v][v].key[0]){
            case 'c':
                vini->chave_c = 1;
                vini->cont_chave ++;
                break;
            case 'd':
                vini->chave_d = 1;
                vini->cont_chave ++;
                break;
            case 'h':
                vini->chave_h = 1;
                vini->cont_chave ++;
                break;
            case 's':
                vini->chave_s = 1;
                vini->cont_chave ++;
                break;
            default:;
        }
}

int Abre_porta(Grafo_t* grafo, Vini_t* vini, int vertex, int vizinho){


    if(vini->cont_chave > 0){
        switch (grafo->mapa[vertex][vizinho].key[0]){
            case 'C':
                if(vini->chave_c == 1)
                    return 1;
                else return 0;
            case 'D':
                if(vini->chave_d == 1)
                    return 1;
                else return 0;
            case 'H':
                if(vini->chave_h == 1)
                    return 1;
                else return 0;
            case 'S':
                if(vini->chave_s == 1)
                    return 1;
                else return 0;
            default:
                return 0 ;
        }
    }
    return 0;
}

int Eh_porta(Grafo_t* grafo, int vertex, int vizinho){

    switch (grafo->mapa[vertex][vizinho].key[0]){
        case 'C':
            return 1;
        case 'D':
            return 1;
        case 'H':
            return 1;
        case 'S':
            return 1;
        default:
            return 0;
    }
}

int Check_saida(Grafo_t* grafo, int* dist, int vertex,int vizinho){

    if(grafo->mapa[vertex][vizinho].key[0] == 'E'){
        if(dist[vizinho] != -1)
            return 1;
        else return 0;
    }

    return 0;
}

void Check_vizinhos(Grafo_t* grafo, Vini_t* vini, int* dist, int* ant,int* visita, int vertex, int i, int* chegou_saida, int* saida, int whole, int whole_fechado){

    int vizinho = 0, eh_porta = 0, abre_porta = 0;
    int k = 0;

    eh_porta = abre_porta= 0;
    vizinho = i;

    eh_porta = Eh_porta(grafo, vertex, vizinho);
    abre_porta = Abre_porta(grafo,vini,vertex, vizinho);

    //situação caso o wormhole leve a um vertice que ja tenha sido visitado no caminho.
    if(whole && No_caminho(ant,vertex,vizinho,vini->pos)){
        k = ant[vertex];
        while(k != vizinho){
            dist[k] = -1;
            visita[k] = 0;
            k = ant[k];
        }
        if(k == vizinho){
            visita[k] = 0;
            dist[k] = -1;
        }
    }
    if(vizinho == whole_fechado){
        visita[vizinho] = 0;
        dist[vizinho] = dist[vertex] + 1;
    }


    if(dist[vizinho] < 0){
        if(whole) {
            dist[vizinho] = dist[vertex];
            ant[vizinho] = vertex;
        }
        else if(eh_porta) {
            if(abre_porta) {
                dist[vizinho] = dist[vertex] + 1;
                ant[vizinho] = vertex;
            }
        }
        else{
            dist[vizinho] = dist[vertex] + 1;
            ant[vizinho] = vertex;
        }
    }
    else{
        if(dist[vizinho] > dist[vertex] + 1) {
            dist[vizinho] = dist[vertex] + 1;
            ant[vizinho] = vertex;
        }
    }
    if(!(*chegou_saida)) {
        *chegou_saida = Check_saida(grafo, dist, vertex, vizinho);
        if(*chegou_saida == 1) *saida = vizinho;
    }
}

int No_caminho(int* ant, int vertex, int vizinho, int inicio){

    int i = 0;

    i = ant[vertex];
    if(vizinho == inicio) return 1;
    while(i != inicio){
        if(i == vizinho) return 1;
        i = ant[i];
    }
    return 0;
}