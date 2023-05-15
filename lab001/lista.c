#include"lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inicializa_lista(Lista * ap_lista){
    *ap_lista = NULL;
}

void insere_fim(Lista * ap_lista, int valor){
    Lista Novo = (Lista) malloc (sizeof(No));
    Novo->valor = valor;
    Novo->proximo = NULL;

    Lista *ap_atual = ap_lista;
    while(*ap_atual){
        ap_atual = &((*ap_atual)->proximo);
    }
    
    *ap_atual = Novo;
}

void insere_inicio(Lista * ap_lista, int valor){
    Lista Novo = (Lista) malloc (sizeof(No));
    
    Novo->valor = valor;
    Novo->proximo = *ap_lista;

    *ap_lista = Novo;
}

int remove_fim(Lista * ap_lista){
    int valor;
    Lista *ap_atual = ap_lista;

    while((*ap_atual)->proximo){
        ap_atual = &((*ap_atual)->proximo);
    }
    
    valor = (*ap_atual)->valor;
    free(*ap_atual);
    *ap_atual = NULL;
    return valor;
}

int remove_inicio(Lista * ap_lista){
    int valor;
    Lista ap_atual = *ap_lista;

    valor = (*ap_lista)->valor;

    *ap_lista = (*ap_lista)->proximo;
    
    free(ap_atual);
    return valor;
}

int remove_ocorrencias(Lista *ap_lista, int valor){
    int cont=0;
    if(!ap_lista) return cont;
    
    Lista *ap_atual = ap_lista;
    Lista ap_remove;

      while((*ap_atual)->proximo){
        if((*ap_atual)->valor == valor){
            cont++;
            ap_remove = *ap_atual;
            *ap_atual = (*ap_atual)->proximo;
            free(ap_remove);
        }
        else {
            ap_atual = &((*ap_atual)->proximo);
        }
        
      }

    if((*ap_atual)->valor == valor){
        remove_fim(ap_lista);
        cont++;
    }

    return cont;
    
}

int busca(Lista lista, int valor){
    Lista *ap_atual = &lista;
    int cont=0;

    while((*ap_atual)->proximo){
        if((*ap_atual)->valor == valor)
          return cont;
        cont++;
        ap_atual = &((*ap_atual)->proximo);
    }
    return -1;
}

void imprime(Lista lista){
  
    printf("(");
    while(lista){
      if(lista->proximo) printf("%d,", lista->valor);
      else printf("%d", lista->valor);

        lista = lista->proximo;
    }
    printf(")");
}

void desaloca_lista(Lista *ap_lista){
    Lista *ap_atual = ap_lista;
    Lista ap_remove;

    while((*ap_atual)->proximo){
        ap_remove = *ap_atual;
        *ap_atual = (*ap_atual)->proximo;
        free(ap_remove);
    }
    free(ap_atual);
    

}