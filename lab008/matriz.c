#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
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
void inicializa_matriz(Matriz * ap_mat, int nlin, int ncol) {
   ap_mat->cabeca = (ListaBidim) malloc(sizeof(No));
   ap_mat->n_linhas = nlin;
   ap_mat->n_colunas = ncol;
   ap_mat->cabeca->linha = ap_mat->cabeca->coluna = -1; 
   ap_mat->cabeca->acima = ap_mat->cabeca->abaixo = ap_mat->cabeca;
   ap_mat->cabeca->direita = ap_mat->cabeca->esquerda = ap_mat->cabeca;     
}

/* Desaloca a memória atualmente utilizada por *mat. Em seguida, 
   inicializa *mat para ser uma matriz de zeros com nlin linhas e
   ncol colunas.  */
void zera(Matriz *ap_mat, int nlin, int ncol){
   desaloca_matriz(&(*ap_mat));
   inicializa_matriz(&(*ap_mat), nlin, ncol);
}

ListaBidim busca_linha(ListaBidim cab, int lin){
   ListaBidim atual = cab->abaixo;
   while(atual != cab){
      if(atual->linha == lin) return atual;
      atual = atual->abaixo;
   }
   return NULL;
}

ListaBidim busca_coluna(ListaBidim cab, int col){
   ListaBidim atual = cab->direita;
   while(atual != cab){
      if(atual->coluna == col) return atual;
      atual = atual->direita;
   }
   return NULL;
}

void insere_linha(ListaBidim cab, ListaBidim linha_cab){
   ListaBidim atual = cab;
   while(atual->abaixo->linha != -1 && atual->abaixo->linha < linha_cab->linha) atual = atual->abaixo;
   linha_cab->abaixo = atual->abaixo;
   atual->abaixo->acima = linha_cab; 
   atual->abaixo = linha_cab;
   linha_cab->acima = atual;
   if(linha_cab->coluna == -1) return;
}

void insere_coluna(ListaBidim cab, ListaBidim coluna_cab){
   ListaBidim atual = cab;
   while(atual->direita->coluna != -1 && atual->direita->coluna < coluna_cab->coluna) atual = atual->direita;
   coluna_cab->direita = atual->direita;
   atual->direita->esquerda = coluna_cab; 
   atual->direita = coluna_cab;
   coluna_cab->esquerda = atual;
   if(coluna_cab->coluna == -1) return;
}

/* Define que o elemento na linha lin e coluna col valerá val. 
   O parâmetro lin está em [0,n_linhas-1] e ncol em [0,n_colunas-1].*/
void define_elemento(Matriz mat, int lin, int col, int val){
   if(lin < 0 || col < 0 || lin >= mat.n_linhas || col >= mat.n_colunas) return;
   ListaBidim linha_cab = busca_linha(mat.cabeca, lin);
   ListaBidim coluna_cab = busca_coluna(mat.cabeca, col);
   if(linha_cab != NULL && coluna_cab != NULL){
      ListaBidim elemento = busca_coluna(linha_cab, col);
      if(elemento != NULL){
         if(val != 0){ 
            elemento->valor = val;
            return;
         }
         elemento->acima->abaixo = elemento->abaixo;
         elemento->esquerda->direita = elemento->direita;
         elemento->direita->esquerda = elemento->esquerda;
         elemento->abaixo->acima = elemento->acima;
         free(elemento);
         return;
      }
   }
   if(val == 0) return;
   if(linha_cab == NULL){
      linha_cab = (ListaBidim) malloc(sizeof(No));
      linha_cab->linha = lin;
      linha_cab->coluna = -1;
      linha_cab->direita = linha_cab->abaixo = linha_cab->esquerda = linha_cab->acima = linha_cab;
      insere_linha(mat.cabeca, linha_cab); 
   }
   if(coluna_cab == NULL){
      coluna_cab = (ListaBidim) malloc(sizeof(No));
      coluna_cab->linha = -1;
      coluna_cab->coluna = col;
      coluna_cab->direita = coluna_cab->abaixo = coluna_cab->esquerda = coluna_cab->acima = coluna_cab;
      insere_coluna(mat.cabeca, coluna_cab); 
   }
   ListaBidim elemento = (ListaBidim) malloc(sizeof(No));
   elemento->valor = val;
   elemento->linha = lin;
   elemento->coluna = col;
   elemento->direita = elemento->abaixo = elemento->esquerda = elemento->acima = elemento;
   insere_linha(coluna_cab, elemento);
   insere_coluna(linha_cab, elemento);
}

ListaBidim busca_posicao(Matriz mat, int lin, int col){
   ListaBidim linha_cab = mat.cabeca->abaixo;
   while(linha_cab->linha != lin && linha_cab != mat.cabeca) linha_cab = linha_cab->abaixo;
   if(linha_cab == mat.cabeca) return NULL;
   ListaBidim aux = linha_cab->direita;
   while(aux != linha_cab){
      if(aux->coluna == col) return aux;
      aux = aux->direita;
   }
   return NULL;
}

/* Computa a soma das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool soma(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_colunas || a.n_linhas != b.n_linhas) return false;
   inicializa_matriz(&(*ap_res), a.n_linhas, a.n_colunas);

   ListaBidim line_a = a.cabeca->abaixo;
   while(line_a != a.cabeca){
      ListaBidim aux = line_a->direita;
      while(aux != line_a){
         define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line_a = line_a->abaixo;
   }
   ListaBidim line_b = b.cabeca->abaixo;
   while(line_b != b.cabeca){
      ListaBidim aux = line_b->direita;
      while(aux != line_b){
         ListaBidim postion = busca_posicao(*ap_res, aux->linha, aux->coluna);
         if(postion != NULL){
            if(postion->valor + aux->valor != 0){
               define_elemento(*ap_res, aux->linha, aux->coluna, postion->valor + aux->valor);
            }else {
               define_elemento(*ap_res, aux->linha, aux->coluna, 0);
            }
         } else if(postion == NULL) {
            define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         }
         aux = aux->direita;
      }
      line_b = line_b->abaixo;
   }
   return true;
 }

/* Computa a subtracao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool subtrai(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_colunas || a.n_linhas != b.n_linhas) return false;
   inicializa_matriz(&(*ap_res), a.n_linhas, a.n_colunas);

   ListaBidim line_a = a.cabeca->abaixo;
   while(line_a != a.cabeca){
      ListaBidim aux = line_a->direita;
      while(aux != line_a){
         define_elemento(*ap_res, aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line_a = line_a->abaixo;
   }
   ListaBidim line_b = b.cabeca->abaixo;
   while(line_b != b.cabeca){
      ListaBidim aux = line_b->direita;
      while(aux != line_b){
         ListaBidim postion = busca_posicao(*ap_res, aux->linha, aux->coluna);
         if(postion != NULL){
            if(postion->valor - aux->valor != 0){
               define_elemento(*ap_res, aux->linha, aux->coluna, postion->valor - aux->valor);
            }else {
               define_elemento(*ap_res, aux->linha, aux->coluna, 0);
            }
         } else if(postion == NULL) {
            define_elemento(*ap_res, aux->linha, aux->coluna, 0 - aux->valor);
         }
         aux = aux->direita;
      }
      line_b = line_b->abaixo;
   }
   return true;
 }

/* Computa a multiplicacao das matrizes a e b colocando o resultado em *ap_res.
 * Libera a memória anteriormente utilizada pelos nos de
 * *ap_res, e sobreescreve *ap_res. */
 bool multiplica(Matriz *ap_res, Matriz a, Matriz b){
   if(a.n_colunas != b.n_linhas) return false;
   zera(&(*ap_res), a.n_linhas, b.n_colunas);

   ListaBidim line_A = a.cabeca->abaixo;
   while (line_A != a.cabeca) {
      ListaBidim column_B = b.cabeca->direita;
      while (column_B != b.cabeca) {
         int line = line_A->linha;
         int column = column_B->coluna;

         int sum = 0;
         ListaBidim element_A = line_A->direita;
         ListaBidim element_B = column_B->abaixo;

         while (element_A != line_A && element_B != column_B) {
            if (element_A->coluna == element_B->linha) {
               sum += element_A->valor * element_B->valor;
               element_A = element_A->direita;
               element_B = element_B->abaixo;
            } else if (element_A->coluna < element_B->linha) {
               element_A = element_A->direita;
            } else {
               element_B = element_B->abaixo;
            }
         }

         if (sum != 0)
            define_elemento(*ap_res, line, column, sum);

         column_B = column_B->direita;
      }

      line_A = line_A->abaixo;
   }

   return true;
}

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
void imprime(Matriz mat){
   printf("(nlin=%d,ncol=%d", mat.n_linhas, mat.n_colunas);
   ListaBidim line = mat.cabeca->abaixo;
   while(line != mat.cabeca){
      ListaBidim aux = line->direita;
      while(aux != line){
         printf(",[%d,%d]=%d", aux->linha, aux->coluna, aux->valor);
         aux = aux->direita;
      }
      line = line->abaixo;
   }
   printf(")\n");
}

/* Desaloca toda a memória alocada da matriz. */
void desaloca_matriz(Matriz *ap_mat){
   ListaBidim aux = ap_mat->cabeca->acima, next;
   while(aux != ap_mat->cabeca){
      next = aux->direita;
      while(next != aux){
         next = next->direita;
         free(next->esquerda);
      }
      aux = aux->acima;
   }
   aux = ap_mat->cabeca->direita;
   while(aux != ap_mat->cabeca){
      aux = aux->direita;
      free(aux->esquerda);
   }
   free(ap_mat->cabeca);
}