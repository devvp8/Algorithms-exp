#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5
#define INF 9999

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
bool visited[MAX_VERTICES];

int minKey(int vertices)
{
    int min = INF, minIndex;
  
    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
  
    return minIndex;
}

void printMST(int vertices)
{
    int mincost=0;
    int spanning[5][5]={0};
    printf("Shortest Paths:\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        mincost+=graph[i][parent[i]];
        spanning[i][parent[i]]=1;
	    spanning[parent[i]][i]=1;
    }
    printf("\nMinimum Cost: %d\n", mincost);
    printf("Spanning Matrix\n");
	for(int i=0;i<vertices;i++)
	{
	    for(int j=0;j<vertices;j++)
	    printf("%d\t",spanning[i][j]);
	    printf("\n");
	}
}

void primMST(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INF;
        visited[i] = false;
    }
  
    key[0] = 0;
    parent[0] = -1;
  
    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(vertices);
  
        visited[u] = true;
  
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
  
    printMST(vertices);
}

int main()
{
    int vertices = MAX_VERTICES;
    primMST(vertices);
  
    return 0;
}
