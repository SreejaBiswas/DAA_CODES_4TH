#include <stdio.h>
#include <stdlib.h>
void initialise(int n, int graph[n+1][n+1], int colours[n+1]){
	int i, j;
	for(i = 1; i<=n; i+=1){
		colours[i] = 0;
		for(j = 1; j<=n; j+=1){
			if(i == j){
				graph[i][j] = 0;
				continue;
			}
			printf("Enter connection (%d, %d) -> ", i, j);
			scanf("%d", &(graph[i][j]));
		}
	}
}
void printGraph(int n, int graph[n+1][n+1]){
	int i, j;
	for(i = 1; i<=n; i+=1){
		for(j = 1; j<=n; j+=1){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
void printColours(int n, int colours[n+1]){
	int i;
	for(i = 1; i<=n; i+=1){
		printf("Vertex (%d) -> Colour (%d)\n", i, colours[i]);
	}
}
int isSafe(int n, int graph[n+1][n+1], int colours[n+1], int row, int column){
	if(graph[row][column] && column == colours[column])
		return 0;
	return 1;
}
int colouring(int n, int graph[n+1][n+1], int colours[n+1], int row){
	if(row > n)
		return 1;
	int j;
	for(j = 1; j<=n; j+=1){
		if(isSafe(n, graph, colours, row, j)){
			colours[row] = j;
			if(colouring(n, graph, colours, row+1))
				return 1;
			colours[row] = 0;
		}
	}
	return 0;
}
int main(){
	int n;
	printf("Enter number of nodes -> ");
	scanf("%d", &n);
	int graph[n+1][n+1], colours[n+1];
	initialise(n, graph, colours);
	colouring(n, graph, colours, 1);
	printColours(n, colours);
	return 0;
}
