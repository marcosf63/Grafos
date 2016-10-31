#define Vertex int
#include <time.h>
typedef Vertex Item;

typedef struct{

  Vertex v;
  Vertex w;
} Arc;

Arc ARC(Vertex v, Vertex w){
  Arc e;
  e.v = v;
  e.w = w;

  return e;
}

#define Edge Arc

#define EDGE ARC

struct digraph{
  int V;
  int A;
  int **adj;
};

typedef struct digraph *Digraph;

#define graph digraph
#define Graph Digraph

int **MATRIXint(int r, int c, int val){
  Vertex i, j;
  int **m = malloc(r * sizeof(int*));
  for (i = 0; i < r; i++)
    m[i] = malloc(c * sizeof(int));
  for(i = 0; i < r; i++)
    for(j = 0; j < c; j++)
      m[i][j] = val;
  return m;
}

Digraph DIGRAPHinit(int V){
  Digraph G = malloc(sizeof*G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w){
  if (v != w && G->adj[v][w] == 0){
    G->adj[v][w] = 1;
    G-> A++;
  }
}

void DIGRAPHshow(Digraph G){
  Vertex v, w;
  for(v = 0; v < G->V; v++){
    printf("%2d:", v);
    for(w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1)
        printf("%2d", w);
    printf("\n");
  }
}


/*A função recebe um Digrafo G e um vértice v e devolve o grau de saída
do vértice v no inteiro grau*/
int DIGRAPHoutdeg(Digraph G, Vertex v){
  Vertex w;
  int outdeg = 0;

  for(w = 0; w < G->V; w++)
    if (G->adj[v][w] == 1)
      outdeg++;
  return outdeg;
}


/*A função recebe um Digrafo G e um vértice v e devolve o grau de saída
do vértice v no inteiro grau*/
int DIGRAPHindeg(Digraph G, Vertex v){
  Vertex w;
  int grau = 0;

  for(w = 0; w < G->V; w++)
    if (G->adj[w][v] == 1)
      grau++;
  return grau;
}

#define maxV 100
static int lbl[maxV];
static int parnt[maxV];

static int caminho[maxV], i;

/*função básica*/
void pathR(Digraph G, Vertex v){
  Vertex w;
  lbl[v] = 0;
  for (w = 0; w < G->V; w++)
    if (G->adj[v][w] == 1)
      if (lbl[w] == -1){
        parnt[w] = v;
        pathR(G, w);
      }
}

/*função básica*/
int DIGRAPHpath(Digraph G, Vertex s, Vertex t){
  Vertex v;
  for (v = 0; v < G->V; v++){
    lbl[v] = -1;
    parnt[v] = -1;
  }
  parnt[s] = s;
  pathR(G, s);
  if (lbl[t] == -1)
    return 0;
  else
    return 1;
}

int st_corte(Digraph G, Vertex s, Vertex t){
  Vertex v, w;
  if (lbl[s] == -1 || lbl[t] == 0)
    return 0;
  for (v = 0; v < G->V; v++)
    for (w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1 &&
          (lbl[v] == 0 && lbl[w] == -1))
            return 0;
  return 1;
}


int DIGRAPHconsistent(Digraph G){
  Vertex v, w;
  int contA = 0;

  for(v = 0; v < G->V; v++)
    for (w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1)
        contA++;
  if (contA != G->A)
    return 0;

  for (v = 0; v < G->V; v++)
    if (G->adj[v][v] == 1)
      return 0;

  return 1;
}

void DIGRAPHdestroy(Digraph G){
  Vertex v;
  for(v = 0; v < G->V; v++)
    free(G->adj[v]);
  free(G->adj);
  free(G);

  G = NULL;
}


Digraph DIGRAPHconstruct(){
  Digraph G;
  FILE *arq;
  int V;
  Vertex v, w;
  arq = fopen("dados.txt", "r");

  if (arq == NULL){
    printf("ERRO ao abrir\n");
    system("pause");
    exit(1);
  }

  fscanf(arq, "%d", &V);
  G = DIGRAPHinit(V);

  while(fscanf(arq, "%d %d", &v, &w) != EOF)
    DIGRAPHinsertA(G, v, w);

  fclose(arq);

  return G;
}

Digraph DIGRAPHaleatorio(int V, int A){
  Vertex v, w;
  
  Digraph G = DIGRAPHinit(V);
  
  srand(time(NULL));
  
  while (G->A < A) {
    v = rand() % V;
    w = rand() % V;
    DIGRAPHinsertA( G, v, w);
  }

  return G;
}

void DIGRAPHcaminho(Digraph G, Vertex s, Vertex t){
  int topo, x, fila[G->V];

    for (x = t, topo = 0; parnt[x] != x; x = parnt[x], topo++)
      fila[topo] = x;
    fila[topo] = x;

    for (;topo >= 0; topo--)
      printf("%d ", fila[topo]);
    printf("\n");
}
