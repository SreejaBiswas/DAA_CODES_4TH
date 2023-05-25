#include <stdio.h>
#include <stdlib.h>
typedef struct ll{
	int data;
	struct ll *next;
} Node;
Node *enqueue(Node *head, int data){
	if(head == NULL){
		head = malloc(sizeof(Node));
		head->data = data;
		head->next = NULL;
		return head;
	}
	head->next = enqueue(head->next, data);
	return head;
}
int dequeue(Node **head){
	Node *temp = *head;
	*head = (*head)->next;
	return temp->data;
}
int isEmpty(Node *head){
	return head == NULL;
}
void initialise(int n, int graph[n][n]){
	for(int i = 0; i<n; i+=1){
		for(int j = 0; j<n; j+=1){
			if(i == j){
				graph[i][j] = 0;
				continue;
			}
			printf("connection from %d to %d -> ", i, j);
			scanf("%d", &(graph[i][j]));
		}
	}
}
void printGraph(int n, int graph[n][n]){
	for(int i = 0; i<n; i+=1){
		for(int j = 0; j<n; j+=1){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
void bfs(int n, int graph[n][n]){
	Node *head = NULL;
	int visited [n];
	for(int i = 0; i<n; i+=1){
		visited[i] = 0;
	}
	head = enqueue(head, 0);
	while(!isEmpty(head)){
		int value = dequeue(&head);
		visited[value] = 1;
		for(int i = 0; i<n; i+=1){
			if((graph[value][i]==1) && (!visited[i])){
				head = enqueue(head, i);
				visited[i] = 1;
			}
		}
		printf("%d ", value);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter the number of vertices -> ");
	scanf("%d", &n);
	int graph[n][n];
	initialise(n, graph);
	printGraph(n, graph);
	bfs(n, graph);
	return 0;
}