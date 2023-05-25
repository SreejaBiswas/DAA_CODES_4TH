#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int minKey(int V, int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
int printMST(int V, int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}
void primMST(int V,int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(V, key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(V,parent, graph);
}
int main()
{
    int V;
    printf("Enter the number of vertices -> ");
    scanf("%d", &V);
    int graph[V][V];
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
        {
		if(i == j){
			graph[i][j] = 0;
			continue;
		}
            printf("%d -> %d -> ", i,j);
            scanf("%d", &graph[i][j]);
		if(graph[i][j] == -1)
			graph[i][j] = INT_MAX;
        }
    primMST(V, graph);
    return 0;
}