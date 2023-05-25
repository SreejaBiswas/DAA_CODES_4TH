#include<stdio.h>

int performJobSchedule(int n, int id[], int st[], int fin[], int A[]) {
     int k=0;
     A[k++] = id[1];
     int j=1, i=2;
     for(i=2; i<n; i++) {
          if(st[i] >= fin[j]) {
               A[k++]=id[i];
               j=i;
          }
     }
     return k;
}

void display(int size, int A[]) {
     printf("Jobs that can be scheduled: { ");
     int i;
     printf("%d", A[0]);
     for(i=1; i<size; i++)
     printf(", %d",A[i]);
     
     printf(" } \n");
}

int main() {
     int n;
     FILE *fptr = fopen("file.txt","rt");
     if(fptr==NULL) {
          printf("File Not Found!");
          return 0;
     }
     
     fscanf(fptr, "%d", &n);
     n+=1;
     int id[n], st[n], fin[n];
     int i=1;
     while(fscanf(fptr, "%d%d%d", &id[i], &st[i], &fin[i])!=EOF)
     i++;
     
     int A[n];
     
     int size = performJobSchedule(n, id, st, fin, A);
     
     display(size, A);  
}



10
1 3 5
2 4 7
3 5 8
4 6 10
5 7 11
6 8 12
7 9 13
8 10 14
9 11 15
10 12 16
