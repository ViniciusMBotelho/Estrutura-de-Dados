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
  //caso o valor nao exista ou a arvore esteja vazia return false
  if(busca(*ap_arv,x) == false) return false;

  //busca o valor na arvore
  if(x < (*ap_arv)->valor) return remove_(&(*ap_arv)->esq,x);
  else if(x > (*ap_arv)->valor) return remove_(&(*ap_arv)->dir,x);

  else {
    if(((*ap_arv)->dir) == NULL && ((*ap_arv)->esq) == NULL){
      (*ap_arv) = NULL;
      return true;
    }else if(((*ap_arv)->dir) == NULL || ((*ap_arv)->esq) == NULL){
      if(((*ap_arv)->dir) == NULL){
        (*ap_arv) = ((*ap_arv)->esq);
        return true;
      }else{
        (*ap_arv) = ((*ap_arv)->dir);
        return true;
       }
    }else {
      Arvore* ap_aux = ap_arv;
      if((*ap_aux)->esq->dir == NULL){
        (*ap_arv)->valor = (*ap_arv)->esq->valor;
        remove_(&((*ap_arv)->esq),(*ap_arv)->valor);
        return true;
      }else if((*ap_aux)->esq->dir != NULL){
        (*ap_aux) = (*ap_aux)->esq;
        while((*ap_aux)->dir != NULL){
          (*ap_aux) = (*ap_aux)->dir;
        }
        (*ap_arv)->valor = (*ap_aux)->valor;
        printf("valor de arv->valor %d",(*ap_arv)->valor);
        remove_(&(*ap_arv)->esq,(*ap_arv)->valor);
        return true;
      }
    }
  }
}

bool busca(Arvore arv, int x){
  if(arv == NULL) return false;

  if(x == arv->valor) return true;
  if(x < arv->valor) return busca(arv->esq,x);
  else if(x > arv->valor) return busca(arv->dir,x);
}