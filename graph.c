#include <stdio.h>
#include <stdlib.h>

// Смежная вершина и вес ребра до неё
struct AdjVertex{
    int dest; // Номер смежной вершины
    int wt; // Вес ребра до смежной вершины
};

// Список смежных вершин для данной вершины
struct AdjList{
    struct AdjVertex *list; 
};

// Структура граф
struct Graph{
    int V; // Количество вершин
    struct AdjList *A; // Массив списков смежных вершин для каждой вершины
};

// Создаёт структуру граф с количеством вершин V
struct Graph *create_graph(int V){
    struct Graph *G = malloc(sizeof(struct Graph));
    G -> V = V;
    G -> A = calloc(V, sizeof(struct AdjList));
    return G;
}

// Удаляет структуру граф по адресу G
void delete_graph(struct Graph *G){
    free(G -> A);
    free(G);
}

int main(void){
    struct Graph *G = create_graph(5);
    delete_graph(G);
    return 0;
}