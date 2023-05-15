#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct No_aux {
  int valor;
  struct No_aux * proximo;
} No;
typedef No * Lista;



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
    Lista *ap_atual = *ap_lista;

    valor = (*ap_lista)->valor;

    *ap_lista = (*ap_lista)->proximo;
    
    free(*ap_atual);
    return valor;
}


int remove_ocorrencias(Lista *ap_lista, int valor){
    int cont=0;
    Lista *ap_atual = &(*ap_lista)->proximo;
    Lista *ap_anterior = ap_lista;


    while(*ap_anterior){
      if((*ap_atual)->proximo == NULL && (*ap_atual)->valor == valor){
          free(*ap_atual);
          *ap_atual = NULL;
          return cont++;
      }
      if(((*ap_atual)->valor && (*ap_atual)->proximo) == valor){
          cont++;
          ap_atual = &((*ap_atual)->proximo);
          free((*ap_anterior)->proximo);
          (*ap_anterior)->proximo = *ap_atual;
          
      }
      ap_anterior = &((*ap_anterior)->proximo);
      ap_atual = &((*ap_atual)->proximo);
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
      if(lista->proximo)
        printf("%d,", lista->valor);
      else
        printf("%d", lista->valor);

        lista = lista->proximo;
    }
    printf(")");
}


int main(){
  int x, conta, posicao;
  char comando[300];
  Lista l;
  inicializa_lista(&l);
  while(scanf("%s", comando) == 1) {
    if (strcmp(comando, "insere_inicio") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_inicio(&l, x);
      printf("Inserido %d no inicio.\n", x);
    }else if (strcmp(comando, "insere_fim") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      insere_fim(&l, x);
      printf("Inserido %d no fim.\n", x);
    }else if (strcmp(comando, "remove_fim") == 0) {
      x = remove_fim(&l);
      printf("Removido %d do fim.\n", x);      
    }else if (strcmp(comando, "imprime") == 0) {
      imprime(l);  
    }else if (strcmp(comando, "remove_inicio") == 0) {
      x = remove_inicio(&l);
      printf("Removido %d do inicio.\n", x);
    }else if (strcmp(comando, "busca") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      posicao = busca(l, x);
      if (posicao == -1) {
	printf("Valor %d nao encontrado na lista.\n", x);
      }else {
	printf("Valor %d encontrado na posicao %d.\n", x, posicao);            
      }
    }else if (strcmp(comando, "remove_ocorrencias") == 0) {
      if(scanf("%d", &x) != 1) return 1;
      conta = remove_ocorrencias(&l, x);
      printf("Removidas %d ocorrencias de %d.\n", conta, x);           
    }
  }
}