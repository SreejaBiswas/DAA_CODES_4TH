#include<stdio.h>
#define INT_MAX 9999999

void init(int v, int G[v][v]) {
     int i, j;
     for(i=1; i<v; i++) {
          for(j=1; j<v; j++) {
               if(i==j)
               G[i][j]=0;
               else
               G[i][j]=INT_MAX;
          }
     }
}

void printIteration(int v, int G[v][v]) {
     int i, j;
     for(i=1; i<v; i++) {
          for(j=1; j<v; j++) {
               if(G[i][j]==INT_MAX)
               printf("INF ");
               else
               printf("%d  ", G[i][j]);
          }
          printf("\n");
     }
     printf("\n");
}

void executeFloydW(int v, int G[v][v]) {
     int i, j, k;
     for(k=1; k<v; k++) {
          printf("Iteration %d\n", k);
          printIteration(v, G);
          for(i=1; i<v; i++) {
               for(j=1; j<v; j++) {
                    if(G[i][k]+G[k][j] < G[i][j])
                    G[i][j] = G[i][k]+G[k][j];
               }
          }
     }
}

void printFinal(int v, int G[v][v]) {
     printf("Final\n");
     printf("Source\t\tDestination\tWeight\n");
     int i, j;
     for(i=1; i<v; i++) {
          for(j=1; j<v; j++) {
               printf("%d\t\t%d\t\t%d\n", i, j, G[i][j]);
          }
     }
}

int main() {
     FILE *fptr = fopen("fileFW.txt", "rt");
     int v, i, j, weight;
     fscanf(fptr, "%d", &v);
     v+=1;
     int G[v][v];
     init(v, G);
     while(fscanf(fptr, "%d%d%d", &i, &j, &weight)!=EOF)
     G[i][j] = weight;
     
     executeFloydW(v, G);   
     printFinal(v, G);                
}

5
1 3 8
1 2 3
1 5 -4
2 5 7
2 4 1
3 2 4
4 3 5
4 1 2
5 4 6

