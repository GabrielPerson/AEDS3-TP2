//
// Created by person on 17/10/16.
//

#ifndef TP2_GRAFO_H
#define TP2_GRAFO_H


typedef struct celula{

    char key[2];
    //char whole[2];
    int cor; //0 -> branco 1-> cinza 2-> preto

}Celula_t;

typedef struct grafo{

    Celula_t** mapa;
    int coluna;
    int linha;

}Grafo_t;


Grafo_t* Cria_grafo(int linha, int coluna);

void Apaga_grafo(Grafo_t* grafo);


#endif //TP2_GRAFO_H
