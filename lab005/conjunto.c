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
    //alocação do vetor de mascaras
    mask = (int *) malloc(n_conjuntos * sizeof(int));

    for(int i=0;i<n_conjuntos;i++) mask[i] = 0;

    //preenchendo o vetor de mascara
    for(i=0; i<n_conjuntos; ++i){
        mask[i] = leitura();
    }        

    uniao(mask,n_conjuntos,alvo);
    
    return 0;
}

//retorna a mascara de cada subconjunto de entrada
int leitura(){
    
    int n_elementos,elemento,mask=0;
    
    scanf("%d",&n_elementos);
    for(int j=0;j<n_elementos;j++){
        scanf("%d",&elemento);
        mask = mask | (1 << elemento);
    }
    return mask;
}

//faz a uniao dos possiveis subconjuntos da solução
void uniao(int mask[], int n_conjuntos, int alvo){

    int soma,colecao[15],n_colecao=0;

    //loop rodando de 0 ate (2^n_conjuntos)-1
    for(int i=0; i<(1<<n_conjuntos); i++){
        soma = 0;
        for(int j=0; j<n_conjuntos; j++){
            //a condição avalia todas as possibilidades e combinações possiveis dos subconjuntos
            if((i & (1 << j)) && ((soma & mask[j]) == 0)){
                //aqueles que foram selecionados sao guardados em um vetor de resultado chamado coleção
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

//função que faz o processo inverso a criação da mascara dos subconjuntos
void output (int n_colecao,int colecao[]){

    int cont_elemento=0; 

    //quantidade de subconjuntos
    printf("%d\n",n_colecao);
    for(int i=0;i<n_colecao;i++){
        for(int j=0;j<15;j++){
            if(colecao[i] & (1 << j)) cont_elemento++;
        }
        //contagem de elementos de cada subconjunto
        printf("%d",cont_elemento);
        cont_elemento=0;
        for(int j=0;j<15;j++){
            //identificação de cada elemento do subconjunto
            if(colecao[i] & (1 << j)) printf(" %d",j);
        }
        printf("\n");
    }
    return;
}