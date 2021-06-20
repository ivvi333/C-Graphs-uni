#ifndef ADD_GRAPHS
#define ADD_GRAPHS

#include <stdio.h>
#include <stdlib.h>

struct Graph *create_graph(int V);
void delete_graph(struct Graph *G, int V);

#endif