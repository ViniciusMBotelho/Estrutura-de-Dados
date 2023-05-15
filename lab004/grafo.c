#include<stdio.h>
#include<stdlib.h>

typedef enum {
    false,true
}bool;

typedef struct no {
    int vertice;
    struct no *prox;
}No;

typedef No* Lista;

typedef struct {
    int n_vet,n_aresta;
    Lista *adj;
}Grafo;

void inicializa_lista (Grafo *G, int num_arestas, int num_vertices){
    G->n_vet = num_vertices;
    G->n_aresta = num_arestas;

    G->adj = (Lista *) malloc(sizeof(Lista) * num_vertices);
    for(int i=0;i<num_vertices;++i){
        G->adj[i] = NULL;
    }
}

void desaloca (Grafo *G){
    free(G->adj);
}

void insere_no (Lista *ap_lista,int valor){
    No** ap_no = ap_lista;

    if(*ap_no == NULL){
        *ap_no = (Lista) malloc(sizeof(No));
        (*ap_no)->vertice = valor;
        (*ap_no)->prox = NULL;
        return;
    }

    while((*ap_no)->prox != NULL){
        ap_no = &((*ap_no)->prox);
    }
    
    (*ap_no)->prox = (Lista) malloc(sizeof(No));
    (*ap_no)->prox->vertice = valor;
    (*ap_no)->prox->prox = NULL;
}

void le_aresta (Grafo *G){
    int vet_1,vet_2;
    for(int i=0;i<G->n_aresta;++i){
        scanf("%d %d",&vet_1,&vet_2);
        insere_no(&G->adj[vet_1],vet_2);
        insere_no(&G->adj[vet_2],vet_1);
    }
}

int contagem_rec (Grafo *G, int vet_ini, int vet_fim, bool *utilizados){
    Lista ap_aux = G->adj[vet_ini];
    bool aux_utili[G->n_aresta];
    int retorno;

    for(int i=0;i<G->n_vet;++i){
        aux_utili[i] = utilizados[i];
    }

    while(ap_aux != NULL){
        if(ap_aux->vertice == vet_fim) return 1;
        utilizados[ap_aux->vertice] = true;
        ap_aux = ap_aux->prox;
    }

    ap_aux = G->adj[vet_ini];
    while(ap_aux != NULL){
        if(aux_utili[ap_aux->vertice] == false){
            retorno = contagem_rec(G,ap_aux->vertice,vet_fim,utilizados);
            if(retorno != 0){
                return 1 + retorno;
            }
        }
        ap_aux = (ap_aux)->prox;  
    }  
    return 0;
}

int contagem (Grafo *G, int vet_ini, int vet_fim){
    bool* utilizados = (bool*) malloc(sizeof(bool) * G->n_vet);
    utilizados[vet_ini] = true;
    return contagem_rec(G,vet_ini,vet_fim,utilizados);

}

int main(){
    Grafo G;
    int quant_vertices,quant_arestas,busca_ini,busca_fim,result;

    scanf("%d %d",&quant_vertices,&quant_arestas);
    if(quant_vertices>50000 || quant_arestas>1000000) return 0;

    inicializa_lista(&G,quant_arestas,quant_vertices);  

    le_aresta(&G);

    scanf("%d %d",&busca_ini,&busca_fim);
    result = contagem(&G,busca_ini,busca_fim);
    if(result == 0){
        printf("infinito\n");
    } 
    else printf("%d\n",result);

    desaloca(&G);
    return 0;
}