Escreva um programa que calcule a distância mínima entre um

par de vértices de um grafo não orientado sem pesos.

Seu programa receberá da entrada uma descrição de um grafo G e de um

par de vértices s e t. A primeira linha da entrada conterá 2 inteiros

N e M, com (N <= 50.000 e M <= 1.000.000), indicando o número de vértices

e de arestas de G, respectivamente. Os vértices de G serão

representados pelos inteiros de 0 a N-1. Em seguida, há M linhas, cada

uma contendo dois inteiros u e v entre 0 e N-1, representando uma

aresta de G que liga u a v. As arestas são bidirecionais, podendo ser

percorridas por caminhos em ambas as direções. Finalmente, há uma

última linha com dois inteiros s e t entre 0 e N-1, representando que

deseja-se descobrir a distância em número de arestas entre s e t.

Seu programa deve imprimir uma única linha com a string

"infinito" se não existir caminho de s para t. Caso exista caminho

de s para t com k arestas, seu programa deve imprimir uma única

linha contendo somente o número k em decimal.
