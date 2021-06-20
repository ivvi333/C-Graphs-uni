#include <stdio.h>
#include <stdlib.h>

// Структура граф
struct Graph{
    int V; // Количество вершин
    int **A; // Матрица смежности
};

// Создаёт структуру граф с количеством вершин V
struct Graph *create_graph(int V){
    struct Graph *G = malloc(sizeof(struct Graph));
    G -> V = V;
    G -> A = malloc(V * sizeof(int *));
    for (size_t i = 0; i < V; i++)
        G -> A[i] = calloc(V, sizeof(int));
    return G;
}

// Удаляет структуру граф по адресу G
void delete_graph(struct Graph *G, int V){
    for (size_t i = 0; i < V; i++)
        free(G -> A[i]);
    free(G -> A);
    free(G);
}

// Создаёт ребро между вершинами src и dst с весом wt
void create_edge(struct Graph *G, int src, int dst, int wt){
    G -> A[src][dst] = wt;
    G -> A[dst][src] = wt;
}

// Выводит граф по адресу G на экран в консоль
void print_graph(struct Graph *G, int V){
    for (size_t i = 0; i < V; i++){
        printf("Vertex %i: ", i);
        for (size_t j = 0; j < V; j++)
            if (G -> A[i][j])
                printf("-%i-> %i, ", G -> A[i][j], j);
        putchar('\n');
    }
}
