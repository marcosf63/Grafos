#define Vertex int
#include <time.h>




typedef struct digraph *Digraph;

typedef struct node *link;


struct node {
  Vertex w;
  link next;
};

struct digraph {
  int V;
  int A;
  link  *adj;
};


#define graph digraph
#define Graph Digraph


link NEW(Vertex w, link next) {
  link p = malloc(sizeof * p);
  p->w = w;
  p->next = next;
  return p;
}


Digraph DIGRAPHinit(int V){
  Vertex v;
  Digraph G = malloc(sizeof*G);
  G->V = V;
  G->A = 0;
  G->adj = malloc(V * sizeof(link));
  for (v = 0; v < V; v++)
    G->adj[v] = NULL;

  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w){
  link p;
  if (v == w) return;
  for (p = G->adj[v]; p != NULL; p = p->next)
    if (p->w == w) return;
  G->adj[v] = NEW(w, G->adj[v]);
  G-> A++;
}

void DIGRAPHshow(Digraph G){
  Vertex v;
  link p;
  for(v = 0; v < G->V; v++){
    printf("%2d:", v);
    for(p = G->adj[v]; p != NULL; p = p->next)
      printf("%2d", p->w);
    printf("\n");
  }
}

Digraph DIGRAPHaleatorio(int V, int A){
  Vertex v, w;
  
  Digraph G = DIGRAPHinit(V);
  
  srand(time(0));
  
  while (G->A < A) {
    v = rand() % V;
    w = rand() % V;
    DIGRAPHinsertA( G, v, w);
  }

  return G;
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w) {
  link p, q;

  p = G->adj[v];
  q = p->next;

  while(q != NULL && q->w != w) {
    p = q;
    q = q->next;
  }
  /*
  if (q != NULL) {
    p->next = q->next;
    free(q);
  }
  */
  p = q;
  free(q);
}






