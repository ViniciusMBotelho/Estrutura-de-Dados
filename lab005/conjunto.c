/*
receber um valor, transformar ele em um vetor binario, depois usar um subconjunto como subcoleção e comparar com os 
outros subconjuntos caso tenha interseção ignorar ele e pular para o proximo subconjunto, caso nao ouver transforme o vetor
binario na uniao da subcoleção

*/

#include<stdio.h>
#include<stdlib.h>

int leitura();
void uniao(int *mask, int n_conjuntos, int alvo);
void output (int n_colecao,int colecao[]);

int main(){
    int *mask,valor,i=0,n_conjuntos,alvo;
    
    scanf("%d",&valor);

    //criação da mascara do alvo
    alvo = 0;
    for(int i=0; i<valor; i++) alvo = alvo | (1 << i); 

    scanf("%d",&n_conjuntos);
    mask = (int *) malloc(n_conjuntos * sizeof(int));

    for(int i=0;i<n_conjuntos;i++) mask[i] = 0;

    //criação o vetor de mascara
    for(i=0; i<n_conjuntos; ++i){
        mask[i] = leitura();
    }        

    uniao(mask,n_conjuntos,alvo);
    
    return 0;
}

int leitura(){
    
    int n_elementos,elemento,mask=0;
    
    scanf("%d",&n_elementos);
        for(int j=0;j<n_elementos;j++){
            scanf("%d",&elemento);
            mask = mask | (1 << elemento);
        }
    return mask;
}

void uniao(int mask[], int n_conjuntos, int alvo){

    int soma,colecao[15],n_colecao=0;

    for(int i=0; i<(1<<n_conjuntos); i++){
        soma = 0;
        for(int j=0; j<n_conjuntos; j++){
            if((i & (1 << j)) && ((soma & mask[j]) == 0)) {
                colecao[n_colecao]=mask[j];
                soma |= mask[j];  
                n_colecao++;
            }
        }
        if(alvo == soma){                       
            output(n_colecao,colecao);
            return;
        }
        n_colecao = 0;
    }
    printf("Insoluvel\n");
    return;
}


void output (int n_colecao,int colecao[]){

    int cont_elemento=0; 

    printf("%d\n",n_colecao);
    for(int i=0;i<n_colecao;i++){
        for(int j=0;j<15;j++){
            if(colecao[i] & (1 << j)) cont_elemento++;
        }
        printf("%d",cont_elemento);
        cont_elemento=0;
        for(int j=0;j<15;j++){
            if(colecao[i] & (1 << j)) printf(" %d",j);
        }
        printf("\n");
    }
    return;
}