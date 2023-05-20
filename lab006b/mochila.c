#include <stdio.h>

#define MAX_N 20

typedef struct {
    int peso, valor, indice;
} Objeto;

int melhor_valor = 0;
int melhor_peso = 0;
int tamanho_melhor_subconjunto = 0;
int melhores_indices[MAX_N];

void encontrar_subconjunto(Objeto S[], int n, int M, int mascara, int peso_subconjunto, int valor_subconjunto, int tamanho_subconjunto, int indices_subconjunto[]) {
    if (peso_subconjunto > M) return;

    if (valor_subconjunto > melhor_valor || (valor_subconjunto == melhor_valor && peso_subconjunto < melhor_peso)) {
        melhor_valor = valor_subconjunto;
        melhor_peso = peso_subconjunto;
        tamanho_melhor_subconjunto = tamanho_subconjunto;
        for (int i = 0; i < tamanho_subconjunto; i++) {
            melhores_indices[i] = indices_subconjunto[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!(mascara & (1 << i))) {
            indices_subconjunto[tamanho_subconjunto] = S[i].indice;
            encontrar_subconjunto(S, n, M, mascara | (1 << i), peso_subconjunto + S[i].peso, valor_subconjunto + S[i].valor, tamanho_subconjunto + 1, indices_subconjunto);
        }
    }
}

int main() {
    int n, M;
    Objeto S[MAX_N];

    scanf("%d %d", &n, &M);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &S[i].peso, &S[i].valor);
        S[i].indice = i;
    }

    int indices_subconjunto[MAX_N] = {0};
    encontrar_subconjunto(S, n, M, 0, 0, 0, 0, indices_subconjunto);

    printf("%d %d\n", melhor_peso, melhor_valor);
    printf("%d", tamanho_melhor_subconjunto);
    for (int i = 0; i < tamanho_melhor_subconjunto; i++) {
        printf(" %d", melhores_indices[i]);
    }
    printf("\n");

    return 0;
}
