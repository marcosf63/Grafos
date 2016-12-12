#include "matriz.c"

int **MATRIXint(int r, int c, int val);
Digraph DIGRAPHinit(int V);
void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w);
void DIGRAPHshow(Digraph G);
void pathR(Digraph G, Vertex v);
int  DIGRAPHpath(Digraph G, Vertex s, Vertex t);
Digraph DIGRAPHaleatorio(int V, int A);

int  DIGRAPHoutdeg(Digraph G, Vertex v);
int  DIGRAPHindeg(Digraph G, Vertex v);
int  DIGRAPHconsistent(Digraph G);
void DIGRAPHdestroy(Digraph G);
Digraph DIGRAPHconstruct();
void DIGRAPHcaminho(Digraph G, Vertex s, Vertex t);
