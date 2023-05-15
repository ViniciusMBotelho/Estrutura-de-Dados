/*fazer como na mascara de bits e selecionar o primeiro valor do vetor, fazer todas as 
combinacoes possiveis para ele e guardar o maior valor possivel dele, depois fazer para o 
seguinte e comparar com um | ate o penultimo*/


#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int peso,valor;
}item;


int main(){
    int quant_conjuntos, peso_max;
    scanf("%d %d",&quant_conjuntos,&peso_max);

    item conjunto[quant_conjuntos];

    for(int i=0;i<quant_conjuntos;++i){
        scanf("%d %d",&conjunto[i].peso,&conjunto[i].valor);
    }

    for(int i=0;i<quant_conjuntos;++i){
        printf("peso: %d, valor: %d",&conjunto[i].peso,&conjunto[i].valor);
    }

    return 0;
}