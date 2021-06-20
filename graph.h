#ifndef ADD_GRAPHS
#define ADD_GRAPHS

#include <stdio.h>
#include <stdlib.h>

struct Graph *create_graph(int V);
void create_edge(struct Graph *G, int src, int dst, int wt);
void delete_edge(struct Graph *G, int src, int dst);
void print_graph(struct Graph *G, int V);
void delete_graph(struct Graph *G, int V);

#endif