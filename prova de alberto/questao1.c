#include<stdlib.h>

typedef struct {
    int x,y;
}ponto;

typedef struct {
    ponto *ap_1, *ap_2, *ap_3;
}triangulo;


main (){
    triangulo *T;
    int valor_1,valor_2;

    T->ap_1 = (ponto *) malloc(sizeof(ponto));
    T->ap_1->x = 1;
    T->ap_1->y = 2;

    T->ap_2 = (ponto *) malloc(sizeof(ponto));
    T->ap_2->x = 3;
    T->ap_2->y = 4;

    T->ap_3 = (ponto *) malloc(sizeof(ponto));
    T->ap_3->x = 5;
    T->ap_3->y = 6;

}