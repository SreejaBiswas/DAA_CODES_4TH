#include<stdio.h>

typedef struct fknap {
     int value, weight, index;
     double vwratio;
}fknap;

int max(int a, int b) {
     return a>b? a : b;
}

void merge(fknap FK[], int lb, int mid, int ub) {
     int i=lb, j=mid+1, k=lb;
     fknap newFK[ub+1];
     
     while(i<=mid && j<=ub) {
          if(FK[i].vwratio >= FK[j].vwratio)
          newFK[k++] = FK[i++];
          else
          newFK[k++] = FK[j++];
     }
     
     while(i<=mid) 
     newFK[k++] = FK[i++];
     
     while(j<=ub)
     newFK[k++] = FK[j++];
     
     for(k=lb; k<=ub; k++)
     FK[k] = newFK[k];
}

void mergeSort(fknap FK[], int lb, int ub) {
     if(lb<ub) {
          int mid=(lb+ub)/2;
          mergeSort(FK, lb, mid);
          mergeSort(FK, mid+1, ub);
          merge(FK, lb, mid, ub);
     }
}

void displaySolVector(int n, double solVector[]) {
     int i;
     printf("Solution Vector: ");
     printf("< %.2f", solVector[0]);
     for(i=1; i<n; i++)
     printf(", %.2f", solVector[i]);
     
     printf(" >\n");
}

void displaySolVectorZO(int n, int  solVector[]) {
     int i;
     printf("Solution Vector: ");
     printf("< %d", solVector[0]);
     for(i=1; i<n; i++)
     printf(", %d", solVector[i]);
     
     printf(" >\n");
}

double fractionalKnapsack(int maxW, fknap FK[], int n) {
     double finVal = 0.0;
     double solVector[n];
     int i, k=0;
     
     for(i=0; i<n; i++) 
     solVector[i]=0.00;
     
     for(i=0; i<n; i++) {
          if(FK[i].weight <= maxW) {
               maxW-=FK[i].weight; 
               finVal += FK[i].value;
               solVector[FK[i].index] = 1;
          }
          else {
               finVal += FK[i].value*((double)maxW / (double)FK[i].weight);
               solVector[FK[i].index] = ((double)maxW / (double)FK[i].weight);
               break;
          }
     }
     
     displaySolVector(n, solVector);
     return finVal;
}

int zeroOneKnapsack(int maxW, int weight[], int value[], int n) {
     int i, w;
     int solVector[n];
     for(i=0; i<n; i++) 
     solVector[i]=0;
     
     int K[n+1][maxW+1];
     
     for(i=0; i<=n; i++) {
          for(w=0; w<=maxW; w++) {
               if(i==0 || w==0) {
                    K[i][w] = 0;
               }
               else if(weight[i-1] <= w) {
                    K[i][w] = max(value[i-1]+K[i-1][w - weight[i-1]], K[i-1][w]);
               }
               else
               K[i][w] = K[i-1][w];
          }
     }

     int result = K[n][maxW], j = maxW;

     for (i = n; i > 0 && result > 0; i--) {
        if (result == K[i-1][j]) {
            continue;
        }
        else {
            solVector[i-1] = 1;
            result = result - value[i-1];
            j = j - weight[i-1];
        }
    }

     displaySolVectorZO(n, solVector);
     return K[n][maxW];
}

int main() {
     int choice;
     printf("Enter:\n1 for 0/1 Knapsack Problem\n2 for Fractional Knapsack Problem\n---> ");
     scanf("%d",&choice);
     
     FILE *fptr = fopen("fileK.txt","rt");
     if(fptr==NULL) {
          printf("File Not Found!");
          return 0;
     }
     
     int n, maxW;
     fscanf(fptr, "%d", &n);
     fscanf(fptr, "%d", &maxW);
     
     if(choice==2) {
          
          fknap FK[n], dupFK[n];
          int i=0;
          
          while(fscanf(fptr, "%d%d", &FK[i].value, &FK[i].weight)!=EOF) {
               FK[i].vwratio = (double)FK[i].value/(double)FK[i].weight;
               FK[i].index = i;
               //printf("%f\n", FK[i].vwratio);
               i++;
          }
          mergeSort(FK, 0, n-1);
          
          printf("Maximum Value: %.2f\n",fractionalKnapsack(maxW, FK, n));
     }
     else if(choice==1) {
          int value[n], weight[n];
          int i=0;
          while(fscanf(fptr, "%d%d", &value[i], &weight[i])!=EOF) {
               i++;
          }
          printf("Maximum Value: %d\n",zeroOneKnapsack(maxW, weight, value, n));
     }    
}

3
20
25 18
24 15
15 10

