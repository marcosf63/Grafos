#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"



int main(){
  Digraph G;
  int V, A, i, v, w;

  printf("Quantidade vertices: ")
  scanf("%d", &V);
  G = DIGRAPHinit(V);
  printf("Quantoidade de arcos: ");
  scanf('%d', &A );
 
  for (i = 0; i < A; i++) {
    printf("Digite o arco v-w: ")
    scand("%d-%d", &v, &w)
  
  }
  DIGRAPHInsertA(G, 0, 1);
  DIGRAPHInsertA(G, 0, 3);
  DIGRAPHInsertA(G, 1, 0);
  DIGRAPHInsertA(G, 1, 1);
  DIGRAPHInsertA(G, 0, 1);
  DIGRAPHInsertA(G, 0, 1);



  DIGRAPHshow(G);



  return 0;
}
