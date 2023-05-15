#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Cê vai pegar o vetor, vai testar todas as posições i do vetor, e testar a interesseção
// entre as outras posições do vetor.

int main() {
  int s, w;
  scanf("%d%d", &s, &w);
  unsigned long long int *setW, setS, index;
  setW = (unsigned long long int *) malloc(w * sizeof(unsigned long long int));

  for(int i = 0;i < w; i++) setW[i] = 1L;

  for(int i = 0; i < w; i++){
    int quantify_elements;
    scanf("%d", &quantify_elements);

    for(int j=0;j<quantify_elements;j++){
      int element;
      scanf("%d", &element);
      setW[i] = setW[i] | (1l << element);
    }

  }
  s = pow(2, s) - 1;
  // for(int i = 0;i < w; i++) printf("%lld ", setW[i]);
  for(int i = 0; i < w; ++i){
    index = 0;
    setS = setW[i];
    index = index | (1l << i);
    for(int j = i + 1; j < w; ++j){
      if(setW[i] & setW[j] == 0){
        setS = setS | setW[j];
        index = index | (1l << j);
      }
    }
    if(setS == s) break;
  }
  if(setS != s){
    printf("Insoluvel");
    return 0;
  }
  

  return 0;
}