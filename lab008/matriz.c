#include "matriz.h"
/*
 * Implemente as seguintes funcoes de um Tipo Abstrato de Dados de uma
 * Matriz esparsa de elementos inteiros. Utilize uma lista circular
 * duplamente ligada com no cabeca bidimensional, sendo uma dimensão
 * para linha e outra para colunas. Somente os elementos nao zero
 * devem ser armazenados. Uma matriz tem dois parâmetros, número de
 * linhas, nlin, e número de colunas, ncol. As linhas da matriz terão
 * índices de 0 a nlin-1. As colunas de 0 a ncol-1. Cada elemento está
 * em precisamente uma linha e uma coluna. Cada par linha e coluna
 * contém precisamente um elemento inteiro.
 */

/* Inicializa uma matriz de zeros com nlin linhas e ncol colunas. 
 * Supõe que não há nada a ser desalocado. */
void inicializa_matriz(Matriz * ap_mat, int nlin, int ncol){
   ap_mat->cabeca = (No*) malloc(sizeof(No));
   ap_mat->n_colunas = ncol;
   ap_mat->n_linhas = nlin;
   ap_mat->cabeca->coluna = ap_mat->cabeca->linha = -1;
   ap_mat->cabeca->abaixo = ap_mat->cabeca->acima = ap_mat->cabeca;
   ap_mat->cabeca->esquerda = ap_mat->cabeca->direita = ap_mat->cabeca;
}

/* Desaloca a memória atualmente utilizada por *mat. Em seguida, 
   inicializa *mat para ser uma matriz de zeros com nlin linhas e
   ncol colunas.  */
void zera(Matriz *ap_mat, int nlin, int ncol){

}

/* Define que o elemento na linha lin e coluna col valerá val. 
   O parâmetro lin está em [0,n_linhas-1] e ncol em [0,n_colunas-1].*/
void define_elemento(Matriz mat, int lin, int col, int val){}

/* Computa a soma das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool soma(Matriz *ap_res, Matriz a, Matriz b){}

/* Computa a subtracao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool subtrai(Matriz *ap_res, Matriz a, Matriz b){}

/* Computa a multiplicacao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool multiplica(Matriz *ap_res, Matriz a, Matriz b){}

/* Imprime a matriz mat no formato do exemplo abaixo
 * (nlin=100,ncol=200,[0,3]=5,[0,8]=10,[2,9]=50,[5,3]=10,[5,15]=20,[99,0]=33)
 * onde esta matriz tem 100 linhas e 200 colunas, e seus únicos
 * elementos não zero são os seguintes:
 * - da linha 0 coluna 3, com valor 5
 * - da linha 0 coluna 8, com valor 10
 * - da linha 2 coluna 9, com valor 50
 * - da linha 5 coluna 3, com valor 10
 * - da linha 5 coluna 15, com valor 20
 * - da linha 99 coluna 0, com valor 33.
 * Os elementos devem ser impressos em ordem crescente de linhas e dois 
 * elementos da mesma linha em ordem crescente de coluna. 
 */
void imprime(Matriz mat){}

/* Desaloca toda a memória alocada da matriz. */
void desaloca_matriz(Matriz *ap_mat){}