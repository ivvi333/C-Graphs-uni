#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Структура граф
struct Graph{
    int V; // Количество вершин
    double *X; // Координаты вершин по x
    double *Y; // Координаты вершин по y
    int **A; // Матрица смежности
};

// Создаёт структуру граф с количеством вершин V
struct Graph *create_graph(int V){
    struct Graph *G = malloc(sizeof(struct Graph));
    G -> V = V;
    G -> X = calloc(V, sizeof(double));
    G -> Y = calloc(V, sizeof(double));
    G -> A = malloc(V * sizeof(int *));
    for (size_t i = 0; i < V; i++)
        G -> A[i] = calloc(V, sizeof(int));
    return G;
}

// Удаляет структуру граф по адресу G
void delete_graph(struct Graph *G){
    int V = G -> V;
    for (size_t i = 0; i < V; i++)
        free(G -> A[i]);
    free(G -> A);
    free(G -> X);
    free(G -> Y);
    free(G);
}

// Создаёт ребро между вершинами src и dst с весом wt
void create_edge(struct Graph *G, int src, int dst, int wt){
    G -> A[src][dst] = wt;
    G -> A[dst][src] = wt;
}

// Удаляет ребро между вершинами src и dst
void delete_edge(struct Graph *G, int src, int dst){
    create_edge(G, src, dst, 0);
}

// Ввод графа с клавиатуры через координаты его вершин
void input_graph(struct Graph *G){
    int V = G -> V;
    double root;
    size_t i = 0, j;
    for (i; i < V; i++){
        scanf("%lf %lf", &(G -> X[i]), &(G -> Y[i]));
        j = i - 1;
        for (j; j >= 0; j--){
            root = sqrt(pow(G -> X[i] - G -> X[j], 2.0) + pow(G -> Y[i] - G -> Y[j], 2.0));
            create_edge(G, i, j, (int) ceil(root));
        }
    }
}

// Выводит граф по адресу G на экран в консоль
void print_graph(struct Graph *G){
    int V = G -> V;
    for (size_t i = 0; i < V; i++){
        printf("Vertex %i: ", i);
        for (size_t j = 0; j < V; j++)
            if (G -> A[i][j])
                printf("-%i-> %i, ", G -> A[i][j], j);
        putchar('\n');
    }
}
