//
// Created by person on 17/10/16.
//

#ifndef TP2_VINI_H
#define TP2_VINI_H

typedef struct vini{

    int cord_x;
    int cord_y;
    int chave_c;
    int chave_d;
    int chave_h;
    int chave_s;
    int cont_chave;
    int tempo;

}Vini_t;

Vini_t* Cria_vini(int inicio_x, int inicio_y);

void Apaga_vini(Vini_t* vini);

#endif //TP2_VINI_H
