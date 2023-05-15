#include "polinomio.h"
#include <stdlib.h>

void inicializa_polinomio(Polinomio * ap_pol){
    No* No_cab = (No*) malloc(sizeof(No));
    *ap_pol = No_cab;
    No_cab->prox = No_cab;
    No_cab->antec = No_cab;
}

void define_coeficiente(Polinomio pol, int grau, int coef){
    if(grau >= 0 && coef != 0){

        No* ap_atual = pol->prox;

        No* novo = (No*) malloc(sizeof(No));
        novo->valor.coef = coef;
        novo->valor.grau = grau;

        while(novo->valor.grau > ap_atual->valor.grau){
            if(ap_atual->prox == pol){
                novo->prox = pol;
                novo->antec = pol->antec;
                pol->antec->prox = novo;
                pol->antec = novo;
                return;
            }
            ap_atual = ap_atual->prox;
        }

        novo->prox = ap_atual;
        novo->antec = ap_atual->antec;
        ap_atual->antec->prox = novo;
        ap_atual->antec = novo;
    }
}

void zera(Polinomio pol){
    No *no_aux = pol->antec;

    while(no_aux != pol){
        pol->antec = pol->antec->antec;
        free(no_aux);
        no_aux = pol->antec;
    }
    pol->prox = pol;
}

void soma(Polinomio res, Polinomio a, Polinomio b){
    zera(res);
    No *no_atual_a = a->prox;
    No *no_atual_b = b->prox;

    int soma_coef;

    while(no_atual_a != a || no_atual_b != b){
        if(no_atual_a->valor.grau == no_atual_b->valor.grau){
            soma_coef = no_atual_a->valor.coef + no_atual_b->valor.coef;
            if(soma_coef != 0)
            define_coeficiente(res, no_atual_a->valor.grau, soma_coef);
            no_atual_a = no_atual_a->prox;
            no_atual_b = no_atual_b->prox;    
        }                                                                       
        else if((no_atual_a->valor.grau < no_atual_b->valor.grau) || (no_atual_b == b && no_atual_a != a)){
            define_coeficiente(res, no_atual_a->valor.grau, no_atual_a->valor.coef);
            no_atual_a = no_atual_a->prox;
        }
        else if ((no_atual_b->valor.grau < no_atual_a->valor.grau) || (no_atual_a == a && no_atual_b != b)){
            define_coeficiente(res, no_atual_b->valor.grau, no_atual_b->valor.coef);
            no_atual_b = no_atual_b->prox;
        }
    }
}

void subtrai(Polinomio res, Polinomio a, Polinomio b){
    zera(res);
    No *no_atual_a = a->prox;
    No *no_atual_b = b->prox;

    int soma_coef;

    while(no_atual_a != a || no_atual_b != b){
        if(no_atual_a->valor.grau == no_atual_b->valor.grau){
            soma_coef = no_atual_a->valor.coef - no_atual_b->valor.coef;
            if(soma_coef != 0)
            define_coeficiente(res, no_atual_a->valor.grau, soma_coef);
            no_atual_a = no_atual_a->prox;
            no_atual_b = no_atual_b->prox;    
        }                                                                       
        else if((no_atual_a->valor.grau < no_atual_b->valor.grau) || (no_atual_b == b && no_atual_a != a)){
            define_coeficiente(res, no_atual_a->valor.grau, no_atual_a->valor.coef);
            no_atual_a = no_atual_a->prox;
        }
        else if ((no_atual_b->valor.grau < no_atual_a->valor.grau) || (no_atual_a == a && no_atual_b != b)){
            define_coeficiente(res, no_atual_b->valor.grau, -no_atual_b->valor.coef);
            no_atual_b = no_atual_b->prox;
        }
    }
}

void imprime(Polinomio pol){
    No *ap_aux = pol->prox;

    printf("[");
    while(ap_aux != pol){
        printf("(%d,%d)",ap_aux->valor.grau,ap_aux->valor.coef);
        if(ap_aux->prox != pol) printf(",");
        ap_aux = ap_aux->prox;
    }
    printf("]\n");
}

void desaloca_polinomio(Polinomio *ap_pol){
    No *aux = (*ap_pol)->prox;
            
    while(aux != (*ap_pol)){
        aux->antec->prox=aux->prox;
        aux->prox->antec=aux->antec;
        free(aux);
        aux = (*ap_pol)->prox;
    }
}