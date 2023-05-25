#include "Arvore.h"
#include<stdio.h>
#include<stdlib.h>

void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}

void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}

bool insere(Arvore* ap_arv, int x){
  if(*ap_arv == NULL){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL) return false;

    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = x;
    *ap_arv = novo;
    return true;
  }

  if(x < (*ap_arv)->valor) return insere(&((*ap_arv)->esq),x);
  else return insere(&((*ap_arv)->dir),x);

  return false;
}

bool remove_(Arvore* ap_arv, int x){
  if(busca(&(*ap_arv),x) == false) return false;

   
}

bool busca(Arvore arv, int x){
  if(arv == NULL) return false;

  if(x == arv->valor) return true;

  if(x < arv->valor) return busca(arv->esq,x);
  else return busca(arv->esq,x);
}