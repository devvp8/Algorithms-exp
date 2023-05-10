#include <stdio.h>
#include <limits.h>

#define V 6 // number of vertices

int graph[V][V] = { // adjacency matrix representation of the graph
    {0, 2, 4, 0, 0, 0},
    {2, 0, 1, 4, 2, 0},
    {4, 1, 0, 0, 3, 0},
    {0, 4, 0, 0, 3, 1},
    {0, 2, 3, 3, 0, 2},
    {0, 0, 0, 1, 2, 0}
};

int dijkstra(int src, int dest) {
    int dist[V]; // array to store the shortest distance from src to each vertex
    int visited[V]; // array to mark visited vertices
    int i, j, min, u;
    
    for (i = 0; i < V; i++) { // initialize the arrays
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    dist[src] = 0; // distance to source vertex is 0
    
    for (i = 0; i < V-1; i++) { // find shortest path to all vertices
        min = INT_MAX;
        
        for (j = 0; j < V; j++) { // find the vertex with the minimum distance
            if (!visited[j] && dist[j] <= min) {
                min = dist[j];
                u = j;
            }
        }
        
        visited[u] = 1; // mark the vertex as visited
        
        for (j = 0; j < V; j++) { // update the distances of adjacent vertices
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u]+graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    
    return dist[dest]; // return the shortest distance to the destination vertex
}

int main() {
    int src = 0; // source vertex
    int dest = 5; // destination vertex
    
    int shortest_distance = dijkstra(src, dest);
    
    printf("Shortest distance from vertex %d to vertex %d is %d\n", src, dest, shortest_distance);
    
    return 0;
}
