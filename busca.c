//
// Created by person on 20/10/16.
//

#include "busca.h"
#include <stdlib.h>
//#include "fila.h"

/* IMPLEENTACAO DE BUSCA DO MENOR CAMINHO DA SAIDA
 *  1 - USA-SE UMA FILA PARA BUSCA EM LARGURA - ENFILERA-SE O VERTICE DE VINI E VERIFICA-SE OS VERTICES ADJS. INSERE NA FILA
 *      E DPS DESENFILERA E CHECA SEUS VIZINHOS TBM
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




int Busca_saida(Grafo_t* grafo, Vini_t* vini, int* dist, int* ant){

    int i = 0, cont = grafo->num_vertex, *visita, v, find_exit = 0;
    int vizinho, whole = 0, abre_porta = 0, eh_porta = 0;
    int *pos_vertex;

    visita = (int*)calloc(grafo->num_vertex, sizeof(int));
    dist[vini->pos] = 0;

    while(cont > 0){

        v = Menor_distancia(dist, visita, grafo->num_vertex);
        if(v == -1)
            break;

        visita[v] = 1;
        cont--;
        whole = 0;
        if(grafo->mapa[v][v].key[0] > 47 && grafo->mapa[v][v].key[0] < 59){
            whole = 1;
            grafo->mapa[v][v].key[0] = '.';
        }


        Check_chave(grafo, vini, v);

        for(i = 0; i < grafo->num_vertex;i++){
            if(grafo->mapa[v][i].number == 1){
                vizinho = i;

                eh_porta = Eh_porta(grafo, v, vizinho);
                abre_porta = Abre_porta(grafo, vini, v, vizinho);

                if(dist[vizinho] < 0){
                    if(whole)
                        dist[vizinho] = dist[v];
                    else if(eh_porta) {
                        if(abre_porta) {
                            dist[vizinho] = dist[v] + 1;
                            ant[vizinho] = v;
                        }
                    }
                    else{dist[vizinho] = dist[v] + 1;
                        ant[vizinho] = v;
                    }
                }
                else{
                    if(dist[vizinho] > dist[v] + 1) {
                        dist[vizinho] = dist[v] + 1;
                        ant[vizinho] = v;
                    }
                }
            }
        }

    }
    Apaga_vetor(visita);

    return dist[vini->pos];
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

void Check_chave(Grafo_t* grafo, Vini_t* vini, int v){

    if(vini->cont_chave < vini->max_chave) {
        switch (grafo->mapa[v][v].key[0]){
            case 'c':
                vini->chave_c = 1;
                break;
            case 'd':
                vini->chave_d = 1;
                break;
            case 'h':
                vini->chave_h = 1;
                break;
            case 's':
                vini->chave_s = 1;
                break;
            default:;
        }
        vini->cont_chave ++;
    }
}

int Abre_porta(Grafo_t* grafo, Vini_t* vini, int vertex, int vizinho){

    //int abre_porta = 0;

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
