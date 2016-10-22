//
// Created by person on 17/10/16.
//

#ifndef TP2_VINI_H
#define TP2_VINI_H

typedef struct vini{

    int chave_c;
    int chave_d;
    int chave_h;
    int chave_s;
    int cont_chave;
    int max_chave;
    int pos;

}Vini_t;

Vini_t* Cria_vini();

void Apaga_vini(Vini_t* vini);

#endif //TP2_VINI_H
