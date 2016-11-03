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

/*
 * Prototipo: Vini_t* Cria_vini(int max_chave);
 *
 * Funcao: Aloca espaco na memoria para o vinicius e define o valor maximo de chaves
 * que podem ser carregadas.
 *
 * Entrada: Tamanho maximo de chaves
 *
 * Saida: variavel do tipo Vini_t* alocada e inicializada.
 */

Vini_t* Cria_vini(int max_chave);

/*
 * Prototipo: void Apaga_vini(Vini_t* vini);
 *
 * Funcao: Libera o espaco na memoria alocado para o vinicius
 *
 * Entrada: variavel do tipo Vini_t*
 *
 * Saida: funcao void
 */

void Apaga_vini(Vini_t* vini);

#endif //TP2_VINI_H
