#include<stdio.h>
#include<limits.h>

int min(int v, int sd[], int visited[]) {
     int min=INT_MAX, minInd,i;
     for(i=1; i<v; i++) {
          if(visited[i]!=1 && min>sd[i]) {
               min = sd[i];
               minInd = i;
          }
     }
     return minInd;
}

void showPath(int v, int par[], int dest, int src, int stack[], int *top) {
     if(par[dest] == src) {
          stack[++(*top)]=dest;
          stack[++(*top)]=par[dest];
          return;
     }
     stack[++(*top)]=dest;
     showPath(v, par, par[dest], src, stack, top);
}

void printMat(int v, int sd[]) {
          int i;
     for(i=1; i<v; i++) {
          if(sd[i] == INT_MAX)
          printf("INF ");
          else
          printf("%d ",sd[i]);
     }
     
     printf("\n");
}

void dijkstra(int v, int G[v][v], int src) {
     int sd[v];
     int par[v];
     int visited[v];
     int i;
     for(i=1; i<v; i++) {
          sd[i]=INT_MAX;
          par[i]=-1;
          visited[i]=0;
     }
     int j;
     sd[src]=0;
     printf("Min weight Matrix: \n");
     for(i=1; i<v-1; i++) {
          int ind = min(v, sd, visited);
          visited[ind]=1;
          for(j=1; j<v; j++) {
               if(G[ind][j]!=0 && visited[j]!=1 && sd[ind]!=INT_MAX && G[ind][j]+sd[ind] < sd[j]) {
                    printMat(v, sd);
                    sd[j] = G[ind][j]+sd[ind];
                    par[j] = ind;
               }
          }
     }
     printMat(v, sd);
     int stack[v], top=-1;
     
     printf("\nPath  Weight\n");
     printf("%d->%d: 0\n",src,src);
     for(i=2; i<v; i++) {
          showPath(v, par, i, src, stack, &top);
          printf("%d",src);
          top--;
          while(top!=-1)
          printf("->%d",stack[top--]);
          
          top=-1;
          printf(": %d", sd[i]);
          printf("\n");
     }
}

int main() {
     FILE *fptr = fopen("dijkstraFile.txt","rt");
     int v;
     fscanf(fptr, "%d", &v);
     v+=1;
     int G[v][v];
     int i, j;
     printf("\nWeight Matrix\n");
     for(i=1; i<v; i++) {
          for(j=1; j<v; j++) {
               fscanf(fptr, "%d",&G[i][j]);
               printf("%d ", G[i][j]);
          }
          printf("\n");
     }
     
     printf("\nEnter source: ");
     int src;
     scanf("%d",&src);
     
     dijkstra(v, G, src);
}
6 8
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 6 1
5 4 2
5 6 5

