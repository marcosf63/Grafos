#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"



int main(){
  Digraph G;
  int V, A, i, v, w;

  printf("Quantidade vertices: ");
  scanf("%d", &V);
  G = DIGRAPHinit(V);
  //DIGRAPHinsertA(G,1,4);
  printf("Quantoidade de arcos: ");
  scanf("%d", &A );
 
  for (i = 0; i < A; i++) {
    printf("Digite o arco v-w: ");
    scanf("%d-%d", &v, &w);
    DIGRAPHinsertA(G, v, w);

  }

  DIGRAPHshow(G);

  if (DIGRAPHpath(G, 1, 4)){
    printf("Caminho exite!\n");

  } else {
    printf("Caminho nao existe\n");
  }
 

  return 0;
}
