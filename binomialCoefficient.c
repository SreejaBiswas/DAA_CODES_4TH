#include<stdio.h>

int findBinoCoeff(int n, int k, int B[n][k]) {
     if(k==0 || k==n)
     return 1;
     
     B[n][k]=findBinoCoeff(n-1, k-1, B) + findBinoCoeff(n-1, k, B);
     return B[n][k];
}

int main() {
     FILE *fptr=fopen("file.txt","rt");
     if(fptr==NULL)
     printf("File Not Found!");
     
     int n,k;
     fscanf(fptr, "%d%d", &n, &k);
     int B[n][k];
     
     printf("Binomial Coefficient of %dC%d is %d\n",n,k,findBinoCoeff(n, k, B));
}



5 2