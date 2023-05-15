Considere o problema de dados conjunto S com n objetos, com funções peso P:S->N e valor V:S->N, e um natural M, encontrar um subconjunto X de S tal que a soma dos pesos dos elementos de X seja menor do que ou igual a M e cuja soma dos valores dos elementos de X seja máxima. Dentre as múltiplas alternativas de máximos possíveis, imprima aquela lexicograficamente menor, considerando lexicograficamente menor aqueles subconjuntos que tenham elementos que aparecem antes na descrição de S. 

A entrada será dada na entrada padrão. A primeira linha conterá dois naturais n e M (n <=20, M<=10^6). As n linhas seguintes conterão 2 naturais cada, representando respectivamente o peso e o valor de um elemento de S.

A saída deve ser dada em duas linhas, descrevendo o conjunto X solução do problema. A primeira linha conterá um natural representando a soma dos pesos de X, seguido de um natural descrevendo a soma dos valores de X. A segunda linha começará com um inteiro k representando o tamanho de X, seguido de k naturais representando os índices, começando em zero, em S dos elementos de X. Em caso de empate no valor de possíveis candidatos a X, o lexicograficamente menor deve ser apresentando. Note que um conjunto X vazio é uma solução possível para o problema. 

Exemplo de entrada:

5 100
30 1000
30 1100
30 1200
40 1500
40 1400


Exemplo de saída

100 3800
3 1 2 3
