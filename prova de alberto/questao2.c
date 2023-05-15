#include<stdlib.h>
#include<stdio.h>

typedef struct no_aux{
    int valor;
    struct no_aux *prox;
}No;

typedef No* Lista;

void inicializa_lista(Lista *ap_lista){
    *ap_lista = (Lista) malloc(sizeof(No));
    (*ap_lista)->prox = NULL;

}

void insere_inicio (Lista ap_lista, int valor){
    Lista novo = (Lista) malloc(sizeof(No));

    novo->prox = (ap_lista)->prox;
    novo->valor = valor;
    (ap_lista)->prox = novo;
}

void insere_fim (Lista ap_lista, int valor){
    Lista ap_aux = ap_lista;
    Lista novo = (Lista) malloc(sizeof(No));

    while((ap_aux)->prox != NULL){
        ap_aux = (ap_aux)->prox; 
    }

    (ap_aux)->prox = novo;
    novo->prox = NULL;
    novo->valor = valor;
}

void imprime(Lista L){
    Lista aux = L->prox;

    printf("(");
    while(aux != NULL){
        printf(" %d ",aux->valor);
        aux = aux->prox;
    }
    printf(")\n");
}

void insere_500 (Lista ap_lista){
    Lista novo = (Lista) malloc(sizeof(No));
    novo->valor = 500;

   novo->prox = ap_lista->prox->prox->prox;
   ap_lista->prox->prox->prox = novo;
}

void remove_segundo (Lista ap_lista){
    Lista ap_aux = ap_lista;
    Lista ap_remove = ap_aux->prox->prox;

    ap_aux->prox->prox = ap_remove->prox;
    free(ap_remove);
}

int main(){
    Lista L;

    inicializa_lista(&L);
    insere_inicio(L,100);
    insere_inicio(L,50);
    insere_fim(L,200);
    imprime(L);
    insere_500(L);
    imprime(L);
    remove_segundo(L);
    imprime(L);

    return 0;
}