#include<stdio.h>

typedef struct {
    int peso,valor;
}item;

int f(int quant_conjuntos, int peso_max, item conjunto[]);

int main(){
    int quant_conjuntos, peso_max;
    scanf("%d %d",&quant_conjuntos,&peso_max);

    item conjunto[quant_conjuntos];

    for(int i=0;i<quant_conjuntos;++i){
        scanf("%d %d",&conjunto[i].peso,&conjunto[i].valor);
    }

    printf("%d\n", f(quant_conjuntos,peso_max,conjunto));
    
    return 0;
}
int max(int a , int b){
    return (a > b ? a : b);
}
int f(int quant_conjuntos, int peso_max, item conjunto[]){
    if(quant_conjuntos == 0 || peso_max == 0) return 0;

    if (conjunto[quant_conjuntos-1].peso > peso_max) return f(quant_conjuntos-1, peso_max, conjunto);
    else return max((conjunto[quant_conjuntos-1]. valor + f(quant_conjuntos-1,peso_max - conjunto[quant_conjuntos-1].peso,conjunto)),
        f(quant_conjuntos-1,peso_max,conjunto));
}


/*pega o primeiro e o segundo item do conjunto (sempre trabalhando em duplas) subtrai o valor do peso
maximo e se possivel somar com os outros itens do conjunto ate ser <= 100, se for guarda numa variavel
maximo, logo em seguida pega o segundo e o terceiro e faz o mesmo, depois o terceiro e o quarto e assim
por diante*/