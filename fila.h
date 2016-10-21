//
// Created by person on 20/10/16.
//

#ifndef TP2_FILA_H
#define TP2_FILA_H

typedef struct celula{
    int coord_i;
    int coord_j;
    struct celula* prox;
} celula_t;

typedef struct fila{
    int tam;
    celula_t* cabeca;
    celula_t* ultimo;
}fila_t;

fila_t* criaFila();
void liberaFila(fila_t* fi);
void enfilera(fila_t* fi, int i, int j);
int* desenfilera(fila_t* fi);
int FilaVazia(fila_t* fi);


#endif //TP2_FILA_H
