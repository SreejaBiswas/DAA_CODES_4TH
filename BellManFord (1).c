#include<stdio.h> 
#include<limits.h>

void init(int d[], int v, int src) {
     int i;
     for(i=0; i<v; i++)
     d[i]=INT_MAX;
     
     d[src]=0; 
}

void printIteration(int v, int d[], int par[]) {
     int i;
     printf("Vertex\tPredecessor\tDist From Source\n");
     for(i=0; i<v; i++) 
     printf("%d\t%d\t\t%d\n",i, par[i], d[i]);
}

void printPath(int v, int par[], int p, int stack[], int *top) {
     if(par[p]==0) {
          stack[++(*top)]=p;
          stack[++(*top)]=par[p];
          return;
     }
     stack[++(*top)]=p;
     printPath(v, par, par[p], stack, top);
}

void display(int stack[], int top, int src) {
     printf("%d",src);
     top--;
     while(top) {
          printf("-->%d",stack[top--]);
     }
}

int executeBMF(int v, int e, int G[e][3], int d[], int par[]) {
     int i, j;
     for(i=1; i<=v-1; i++) {
          for(j=0; j<e; j++) {
               int u = G[j][0];
               int v = G[j][1];
               int weight = G[j][2];
               if(d[u] + weight < d[v]) {
                    d[v] = d[u] + weight;
                    par[v] = u;
               }
          }
          printf("Weight after Iteration %d\n",i);
          printIteration(v, d, par);
     }
     for(j=0; j<e; j++) {
          int u = G[j][0];
          int v = G[j][1];
          int weight = G[j][2];
          if(d[u] + weight < d[v])
          return 0;
     }
     return 1;
}

void printFinal(int v, int d[], int par[]) {
     printf("Final weights\n");
     int i;
     printf("Vertex\tPredecessor\tDist From Source\n");
     for(i=0; i<v; i++) 
     printf("%d\t%d\t\t%d\n",i, par[i], d[i]);
}

int main() {
     FILE *fptr = fopen("fileBMF.txt","rt");
     int V, e, i=0;
     fscanf(fptr, "%d%d", &V, &e);
     
     int G[e][3];
     int d[V], par[V];
     printf("Enter the source: ");
     int src;
     scanf("%d",&src);
     par[src] = -1;
     init(d, V, src);
     
     //G[i][0] source
     //G[i][1] dest
     //G[i][2] weight
     
     while(fscanf(fptr, "%d%d%d", &G[i][0], &G[i][1], &G[i][2])!=EOF)
     i++;
     
     
     if(executeBMF(V, e, G, d, par)==1) {
          printFinal(V, d, par);
          printf("\n");
          printf("Path:\n");
          for(i=1; i<V; i++) {
               int stack[V], top=0;
               printPath(V, par, i, stack, &top);
               display(stack, top, src);
               printf("\n");
          }
     }
     else
     printf("The graph contains a negative cycle!");
}
5 10
0 1 6
0 4 7
1 2 5
1 4 8
1 3 -4
2 1 -2
3 2 7
3 0 8
4 2 -3
4 3 9