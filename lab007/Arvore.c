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
  else if(x > (*ap_arv)->valor) return insere(&((*ap_arv)->dir),x);

  return false;
}

bool remove_(Arvore* ap_arv, int x){
  Arvore *ap_aux = ap_arv;
  if(busca(*ap_arv,x) == false) return false;

  while(x != (*ap_aux)->valor){
    if((*ap_aux)->valor < x) (*ap_aux) = (*ap_aux)->esq;
    else (*ap_arv) = (*ap_aux)->dir;
  }

  if((*ap_aux)->esq == NULL && (*ap_aux)->dir == NULL){
    free(ap_aux);
    ap_aux == NULL;
  }else if((*ap_aux)->esq == NULL || (*ap_aux)->dir == NULL){
    (*ap_aux)->esq == NULL ? ((*ap_aux) = (*ap_aux)->dir) : ((*ap_aux) = (*ap_aux)->esq);
  }else{
    
  }
}

bool busca(Arvore arv, int x){
  if(arv == NULL) return false;

  if(x == arv->valor) return true;
  if(x < arv->valor) return busca(arv->esq,x);
  else if(x > arv->valor) return busca(arv->dir,x);
}