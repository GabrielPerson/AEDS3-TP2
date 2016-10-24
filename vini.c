//
// Created by person on 17/10/16.
//

#include "vini.h"
#include <stdlib.h>

Vini_t* Cria_vini(int max_chave){

    Vini_t* vini;

    vini = (Vini_t*)calloc(1, sizeof(Vini_t));

    vini->chave_c = 0;
    vini->chave_d = 0;
    vini->chave_h = 0;
    vini->chave_s = 0;
    vini->cont_chave = 0;
    vini->max_chave = max_chave;
    vini->pos = 0;

    return vini;
}

void Apaga_vini(Vini_t* vini){

    free(vini);
    vini = NULL;

}