#ifndef ADD_GRAPHS
#define ADD_GRAPHS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Graph{
    int V;
    double *X;
    double *Y;
    int **A;
};

struct Graph *create_graph(int V);
void create_edge(struct Graph *G, int src, int dst, int wt);
void delete_edge(struct Graph *G, int src, int dst);
void input_graph(struct Graph *G);
void print_graph(struct Graph *G, int V);
void delete_graph(struct Graph *G, int V);

#endif