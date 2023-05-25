#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
void initialize_graph(int cost[][MAX_VERTICES], int n);
void kruskal_algorithm(int cost[][MAX_VERTICES], int n);
int find(int i, int parent[]);
int union_vertices(int i, int j, int parent[]);
int main() {
	int n, cost[MAX_VERTICES][MAX_VERTICES];
	printf("\nImplementation of Kruskal's algorithm\n");
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	initialize_graph(cost, n);
	kruskal_algorithm(cost, n);
	return 0;
}
void initialize_graph(int cost[][MAX_VERTICES], int n) {
	int i, j;
	printf("Enter the cost adjacency matrix:\n");
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(i == j){
				cost[i][j] = 0;
				continue;
			}
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == -1) {
				cost[i][j] = 999;
			}
		}
	}
}
void kruskal_algorithm(int cost[][MAX_VERTICES], int n) {
	int i, j, a, b, u, v, ne = 1, min, mincost = 0, parent[MAX_VERTICES];
	for(i = 1; i <= n; i++) {
		parent[i] = 0;
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n) {
		for(i = 1, min = 999; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(cost[i][j] < min) {
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u, parent);
		v = find(v, parent);
		if(union_vertices(u, v, parent)) {
			printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	for(i = 1; i <= n; i++) {
		if(find(i, parent) != find(1, parent)) {
			printf("Error: Graph is not connected\n");
			return;
		}
	}
	printf("Minimum cost = %d\n", mincost);
}
int find(int i, int parent[]) {
	while(parent[i]) {
		i = parent[i];
	}
	return i;
}
int union_vertices(int i, int j, int parent[]) {
	if(i != j) {
		parent[j] = i;
		return 1;
	}
	return 0;
}