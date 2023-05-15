#include "lista.h"
#include <stdlib.h>

void inicializa_lista(Lista * ap_lista){
    No* No_cab = (No*) malloc(sizeof(No));
    *ap_lista = No_cab;
    No_cab->prox = No_cab;
    No_cab->antec = No_cab;
}

void insere_fim(Lista ap_lista, TipoDado valor){
    No* Novo = (No*) malloc (sizeof(No));
    Novo->valor = valor;

    Novo->prox = ap_lista;
    Novo->antec = ap_lista->antec;
    ap_lista->antec->prox = Novo; 
    ap_lista->antec = Novo;
}

void insere_inicio(Lista ap_lista, TipoDado valor){
    No* Novo = (No*) malloc (sizeof(No));
    Novo->valor = valor;

    Novo->prox = ap_lista->prox;
    Novo->antec = ap_lista;
    ap_lista->prox->antec = Novo;
    ap_lista->prox = Novo;
}

TipoDado remove_fim(Lista ap_lista){
    No * ap_remove = ap_lista->antec;
    TipoDado valor_removido;

    if(ap_lista->prox == ap_lista) return ap_lista->valor;
        
    ap_lista->antec->antec->prox = ap_lista;
    ap_lista->antec = ap_lista->antec->antec;
    valor_removido = ap_remove->valor;
    free(ap_remove); 
    return valor_removido;
}

TipoDado remove_inicio(Lista ap_lista){
    No * ap_remove = ap_lista->prox;
    TipoDado valor_removido;

    if(ap_lista->prox == ap_lista) return ap_lista->valor;

    ap_lista->prox->prox->antec = ap_lista;
    ap_lista->prox = ap_lista->prox->prox;
    valor_removido = ap_remove->valor;
    free(ap_remove);
    return valor_removido;
}

int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    int cont = 0;
    No * ap_atual = ap_lista->prox;
    No * ap_remove;
    
    if(ap_lista->prox == ap_lista){
        if(ap_atual->valor.coef == valor.coef && ap_atual->valor.grau == valor.grau){
            remove_fim(ap_lista);
        }
        return cont;
    }
    while(ap_atual != ap_lista){
        if(ap_atual->valor.coef == valor.coef && ap_atual->valor.grau == valor.grau){  
            ap_atual->antec->prox = ap_atual->prox;
            ap_atual->prox->antec = ap_atual->antec;
            ap_remove = ap_atual;
            cont++;
            free(ap_remove);
        }
            ap_atual = ap_atual->prox;
    }
    return cont;
}

int busca(Lista lista, TipoDado valor){
    int cont = -1;
    No * ap_atual = lista->prox;

    while(ap_atual != lista){
        cont++;
        if(ap_atual->valor.coef == valor.coef && ap_atual->valor.grau == valor.grau) return cont;
        ap_atual = ap_atual->prox;
    }
    return cont;
}

int coeficiente_do_grau(Lista lista, int grau){
    No * ap_atual = lista->prox;
    int grau_teste = 0;
    
    while(ap_atual != lista){
        if(ap_atual->valor.grau == grau) {
            grau_teste = ap_atual->valor.coef;
            return grau_teste;
        }
        ap_atual = ap_atual->prox;
    }
    return grau_teste;
}

void imprime(Lista lista){
    No *ap_aux = lista->prox;

    printf("[");
    while(ap_aux != lista){
        printf("(%d,%d)",ap_aux->valor.grau,ap_aux->valor.coef);
        if(ap_aux->prox != lista) printf(",");
        ap_aux = ap_aux->prox;
    }
    printf("]\n");
}

void desaloca_lista(Lista *ap_lista){
    No *aux = (*ap_lista)->prox;
            

    while(aux!=*ap_lista){
        aux->antec->prox=aux->prox;
        aux->prox->antec=aux->antec;
        free(aux);
        aux = (*ap_lista)->prox;
    }
}